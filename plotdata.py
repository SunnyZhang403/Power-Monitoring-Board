import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('Power-Data.csv')
currentlabels = []
values = {'Averages':{}, 'Min':{}, 'Max':{}}
for column in data.columns[3:11]:
    plt.plot(data['Time (s)'], data[column])
    values['Averages'][column] = data[column].mean()
    values['Max'][column] = data[column].max()
    values['Min'][column] = data[column].min()
    currentlabels.append(column)
for k in values.keys():
    print(values[k])
plt.xlabel('Time (s)')
plt.ylabel('Current (A)')
plt.minorticks_on()
plt.grid(True)
plt.legend(currentlabels)
plt.savefig('Time-Current.png')
plt.clf()

plt.plot(data['Time (s)'], data['Voltage (V)'])
plt.xlabel('Time (s)')
plt.ylabel('Voltage (V)')
plt.minorticks_on()
plt.grid(True)
plt.legend(['Voltage (V)'])
plt.savefig('Time-Voltage.png')
plt.clf()
powerlabels = []
for column in data.columns[11:]:
    plt.plot(data['Time (s)'], data[column])
    values['Averages'][column] = data[column].mean()
    values['Max'][column] = data[column].max()
    values['Min'][column] = data[column].min()
    powerlabels.append(column)
plt.xlabel('Time (s)')
plt.ylabel('Current (A)')
plt.minorticks_on()
plt.grid(True)
plt.legend(powerlabels)
plt.savefig('Time-Power.png')
plt.clf()