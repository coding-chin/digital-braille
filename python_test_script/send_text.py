import serial
import time

port = "COM3"  # Change to your ESP32 port
baud = 115200

ser = serial.Serial(port, baud)
time.sleep(2)

text = input("Enter text to send: ")
ser.write((text + "\n").encode())

ser.close()
