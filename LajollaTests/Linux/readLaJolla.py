#!/usr/bin/python3
#
# Read A/D-conversion results from /dev/ttyUSB0, add
# timestamps and store to file.
#
# To allow users access the serial port, use e.g. the following command
#
#     sudo adduser $USER dialout
#
# and then log out and log in again for the changes to be effective.

import datetime as dt
import serial
import time

ser = serial.Serial("/dev/ttyUSB0",115200,timeout=5)
ser.flush()

# Wait for 10s before printing a timeout value

while 1:
    n = 0
    while (ser.in_waiting == 0 & n < 20):
        time.sleep(0.5)
        n = n+1

    mytimestamp=time.time()
    mydt=dt.datetime.utcfromtimestamp(mytimestamp)
    filename=mydt.strftime("lyr%Y%m%d.txt")
    if ser.in_waiting>0:
    #    mytimestamp = time.time()
        line = ser.readline().decode('utf-8').rstrip()
        voltage=int(line)
        with open(filename,"a") as of:
            of.write(str(round(mytimestamp))+" "+ str(voltage) + " 0\n")
        print(round(mytimestamp), voltage, 0, "->", filename)
    else:
        with open(filename,"a") as of:
            of.write(str(round(mytimestamp))+" -1 0\n")
        print(round(mytimestamp),-1,0)
