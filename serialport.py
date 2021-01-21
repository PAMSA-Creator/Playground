import serial
from time import sleep
setS = serial.Serial ('COM12', baudrate=9600)
x=0
while (x<50):
     x+=1
     command = input ("Enter your command:")
     setS.write(command.encode())
     sleep(5)
print ("DONE")
