import numpy
import math
import time
import serial
import serial.tools.list_ports
from numpy.ma.core import arcsin

ports = serial.tools.list_ports.comports()
for port in ports:
    print(port)

ser=serial.Serial('COM10',115200,timeout=1)


def imu_sensor():
    while True:
        accel=numpy.round(numpy.random.uniform(-100,100,3),2)
        gyro=numpy.round(numpy.random.uniform(-250,250,3),2)
        mag=numpy.round(numpy.random.uniform(-50,50,3),2)
        euler=numpy.round(numpy.random.uniform(-180,180,3),2)
        g=accel[2]

        print(f"Accelerometer: {accel}, Gyroscope: {gyro}, Magnetometer: {mag}, Euler: {euler}")

        data=f"{accel[0]},{accel[1]},{accel[2]},{gyro[0]},{gyro[1]},{gyro[2]},{mag[0]},{mag[1]},{mag[2]},{euler[0]},{euler[1]},{euler[2]}\n"
        ser.write(data.encode())
        time.sleep(0.1)

imu_sensor()