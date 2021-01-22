import serial
s = serial.Serial ('COM12', baudrate=9600)
print ("Ha ha")
com = None
while com == None:
    try:
        com = input ("Write Command:")
        print (com)
        
    except:
         pass
s.write(com.encode())
print (s.readline())
