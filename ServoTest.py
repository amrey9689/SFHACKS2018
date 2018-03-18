import serial
import Tkinter
import numpy as np
import struct
import time

ser = serial.Serial('/dev/ttyACM0', 9600)

#0,0 = 'A'
#0,1 = 'B'
#0,2 = 'C'
#1,0 = 'D'
#1,1 = 'E'
#1,2 = 'F'
#2,0 = 'G'
#2,1 = 'H'
#2,2 = 'I'

def sercommunicate(coord):
    #write to arduino
    ser.write(coord)
    #testoutput
    #print(coord)

def sendData(framex, framey, objectx, objecty):
    #declare coord as char
    coord=''

    #centerofobject(x,y)
    #up is neg down is positive
    #left is negative right is positive
    #- -        #+ -
    #- +        #+ +

    #send data based on one of the 9 permutations
    if((framex == objectx)and(framey == objecty)):
        #0,0
        coord='A'
    elif((framex == objectx)and(framey < objecty)):
        #(0,1)
        coord='B'
    elif((framex == objectx)and(framey > objecty)):
        #(0,2)
        coord='C'
        
    elif((framex < objectx)and(framey == objecty)):
        #1,0
        coord='D'
    elif((framex < objectx)and(framey < objecty)):
        #(1,1)
        coord='E'       
    elif((framex < objectx)and(framey > objecty)):
        #(1,2)
        coord='F'
        
    elif((framex > objectx)and(framey == objecty)):
        #2,0
        coord='G'
    elif((framex > objectx)and(framey < objecty)):
        #(2,1)
        coord='H'
    elif((framex > objectx)and(framey > objecty)):
        #(2,2)
        coord='I'

    #send coordinates
    sercommunicate(coord)
 

    
