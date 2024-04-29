import serial
import pandas as pd
import keyboard
import numpy as np

inputport = 'COM3'
temp = []
arduino = serial.Serial(inputport, 9600)
datalist = {'Time (s)':[], 'Voltage (V)':[]}
n = 8
for i in range (1,n+1):
    datalist['Current %d (A)'%i] = []
for i in range(1, n+1):
    datalist['Power %d (W)'%i] = []

t = 0
while True:
    getdata = arduino.readline()
    rawdata = getdata.decode('utf-8')
    data = rawdata.split('x')
    for n, value in enumerate(data[:-1]):
        if n == 0:
            datalist['Voltage (V)'].append(value)
        else:
            datalist['Current %d (A)'%n].append(value)
            datalist['Power %d (W)'%n].append(float(value)*float(data[0]))
    datalist['Time (s)'].append(t)
    if keyboard.is_pressed('e'):
        for k in datalist.keys():
            temp.append(datalist[k])
        print(temp)
        datanp = np.array(temp)
        datadf = pd.DataFrame(np.transpose(datanp), columns = datalist.keys())
        datadf.to_csv('Power-Data.csv')
        break
    t = t+0.01
