import cv2
import urllib.request
import numpy as np
import bluetooth #pybluez library
import time

bd_addr ='00:19:09:03:01:6A'
url = "http://192.168.43.227:8081/shot.jpg"
sock = bluetooth.BluetoothSocket( bluetooth.RFCOMM )
sock.connect((bd_addr,1))
sock.send('5')
time.sleep(0)
sock.send('0')
tracker = cv2.TrackerCSRT_create()
imgResp = urllib.request.urlopen(url)
imgNp = np.array(bytearray(imgResp.read()), dtype=np.uint8)
frame = cv2.imdecode(imgNp, -1)
bbox = cv2.selectROI("Tracking",frame, False)
tracker.init(frame, bbox)
w1=bbox[2]

while True:
    imgResp = urllib.request.urlopen(url)
    imgNp = np.array(bytearray(imgResp.read()), dtype=np.uint8)
    img = cv2.imdecode(imgNp, -1)
    success, bbox = tracker.update(img)
    x, y, w, h = int(bbox[0]), int(bbox[1]), int(bbox[2]), int(bbox[3])
    cv2.rectangle(img, (x, y), ((x + w), (y + h)), (255, 0, 255), 3, 3 )
    x = x + (w1 / 2)
    t = int((x * 7) / 720) + 2
    if (y < 0):
        t = 10 - t
        sock.send(str(t))
        time.sleep(0)
        sock.send('9')
        time.sleep(0)
    else:
        sock.send(str(t))
        time.sleep(0)
        if (x > 110 and x < 610 and y < 50):
            sock.send('0')
            time.sleep(0)
        else:
            sock.send('1')
            time.sleep(0)
    cv2.imshow("Tracking", img)
    if ord('q') == cv2.waitKey(10):
        sock.send('0')
        exit(0)


