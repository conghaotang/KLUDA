import matplotlib.pyplot as plt			# 导入模块
import numpy as np
import math

plt.rcParams['font.sans-serif']=['SimHei']
plt.rcParams['axes.unicode_minus']=False
plt.rcParams['font.size']=10

p=30
delta_time =0.1
simulation_time =400-delta_time*p
x_time=np.arange(0,simulation_time,delta_time)

def loop_mc(data):
    data_set = [float(data[i]) for i in range(0,int(2*simulation_time/delta_time))]
    data1 = [0 for i in range(0,int(simulation_time/delta_time))]
    data2 = [0 for i in range(0,int(simulation_time/delta_time))]
    for i in range(0, int(simulation_time/delta_time)):
        data1[i] = data_set[i*2]
        data2[i] = data_set[i * 2+1]
    return data1,data2

def rmse(data):
    result_rmse =0
    for i in data:
        result_rmse = result_rmse +i**2
    return math.sqrt(result_rmse / len(data))


fig, (ax1) = plt.subplots(1, 1, figsize=(5, 6),dpi=150)
data =open(r'D:\vs项目\KLUDA\result\true_state1.txt','r')
data1 = data.read().split(",")
data1,data2  = loop_mc(data1)
data.close()
ax1.plot(x_time, data1,  color='red', alpha=0.8, linewidth=1.5, label='state1')
ax1.plot(x_time, data2,  color='blue', alpha=0.8, linewidth=1.5, label='state2')
ax1.legend()
#plt.axhline(15, 0, 59.95,color="red")#横线
#plt.axhline(-15, 0, 59.95,color="red")#横线
#plt.axvline(x=2,ymin=0,ymax=1,linestyle="dashed")
plt.show()
print(rmse(data1))
print(rmse(data2))

