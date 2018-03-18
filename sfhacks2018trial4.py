from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import numpy as np
import math
import ServoTest as servo

camera=PiCamera()
camera.resolution=(640,480)
camera.framerate=30
rawCapture=PiRGBArray(camera, size=(640, 480))
middleofframe = (320, 240)

time.sleep(0.1)

#GREEN
#lower_green=np.array([29, 86, 6])
#upper_green=np.array([64, 255, 255])

#ORANGE
#lower_green=np.array([0, 70, 50])
#upper_green=np.array([10, 255, 255])

#WHITE
lower_green=np.array([0, 210, 210], dtype=np.uint8)
upper_green=np.array([255, 255, 255], dtype=np.uint8)

for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
    image = frame.array

    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(image, lower_green, upper_green)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)

    cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)[-2]
    centerofobject = middleofframe
    
    if len(cnts) > 0:
        c = max(cnts, key=cv2.contourArea)
        ((x,y), radius) = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)
        centerofobject = (int(M["m10"]/M["m00"]), int(M["m01"]/M["m00"]))

        if radius >10:
            cv2.circle(image, (int(x), int(y)), int(radius), (0, 255, 255), 2)
            cv2.circle(image, centerofobject, 5, (0, 0, 255), -1)
    
    res = cv2.bitwise_and(image, image, mask=mask)
    cv2.imshow('image', image)
    cv2.imshow('res' ,res)

    key=cv2.waitKey(1) & 0xFF

    rawCapture.truncate(0)
    coords = (centerofobject[0] - middleofframe[0], centerofobject[1] - middleofframe[1])
    servo.sendData(middleofframe[0], middleofframe[1], centerofobject[0], centerofobject[1])

    

    if key == ord("q"):
        break
    
