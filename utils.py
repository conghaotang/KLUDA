import numpy as np
import math

p=30
delta_time =0.1
simulation_time =200-delta_time*p
x_time=np.arange(0,simulation_time,delta_time)

def loop_mc(data):
    data_set = [float(data[i]) for i in range(0,int(2*simulation_time/delta_time))]
    data1 = [0 for i in range(0,int(simulation_time/delta_time))]
    data2 = [0 for i in range(0,int(simulation_time/delta_time))]
    for i in range(0, int(simulation_time/delta_time)):
        data1[i] = data_set[i*2]
        data2[i] = data_set[i * 2+1]
    return data1,data2
"""
def rmse(data):
    result_rmse =0
    for i in data:
        result_rmse = result_rmse +i**2
    return math.sqrt(result_rmse / len(data))
"""
def draw_data(data):
    data = data.read().split(",")
    return loop_mc(data)

def mean(data1,data2):
    mean=0
    for i in range(0,len(data1)):
        mean = mean+(data1[i]-data2[i])
    return mean/len(data1)

def rmse(data1,data2):
    result_rmse = 0
    for i in range(0, len(data1)):
        result_rmse = result_rmse + (data1[i] - data2[i])**2
    return math.sqrt(result_rmse/len(data1))