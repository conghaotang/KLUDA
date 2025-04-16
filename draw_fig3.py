import matplotlib.pyplot as plt			# 导入模块
import numpy as np
import math
from utils import draw_data,mean,rmse


plt.rcParams['font.sans-serif']=['Times New Roman']
plt.rcParams['axes.unicode_minus']=False
plt.rcParams['font.size']=10


p=30
delta_time =0.1
simulation_time =200-delta_time*p
x_time=np.arange(0,simulation_time,delta_time)


fig, ((ax1, ax2, ax3)) = plt.subplots(3, 1, figsize=(8, 6),dpi=300)
kluda_data =open(r'D:\vs项目\KLUDA\result\kluda10.txt','r')
ufir_data =open(r'D:\vs项目\KLUDA\result\ufir10.txt','r')
true_data =open(r'D:\vs项目\KLUDA\result\true10.txt','r')
kluda_data1,kluda_data2 = draw_data(kluda_data)
ufir_data1,ufir_data2=draw_data(ufir_data)
true_data1,true_data2=draw_data(true_data)
print(str(mean(kluda_data1,true_data1))+"   "+str(rmse(kluda_data1,true_data1)))
print(str(mean(ufir_data1,true_data1))+"   "+str(rmse(ufir_data1,true_data1)))
print(str(mean(kluda_data2,true_data2))+"   "+str(rmse(kluda_data2,true_data2)))
print(str(mean(ufir_data2,true_data2))+"   "+str(rmse(ufir_data2,true_data2)))
ax1.plot(x_time[::20], kluda_data1[::20], '*', color='blue', alpha=0.8, linewidth=1.5, label='KUFIR1')
ax1.scatter(x_time[::20], ufir_data1[::20],  marker='o', facecolors='none',edgecolors='r', s=50, label='TUFIR1')
ax1.plot(x_time[::20], true_data1[::20], color='green',  alpha=0.8, linewidth=1.5, label='TRUE')
ax1.legend(ncol = 3)


plt.subplot(3,1,2)
kluda_data =open(r'D:\vs项目\KLUDA\result\kluda20.txt','r')
ufir_data =open(r'D:\vs项目\KLUDA\result\ufir20.txt','r')
true_data =open(r'D:\vs项目\KLUDA\result\true20.txt','r')
kluda_data1,kluda_data2 = draw_data(kluda_data)
ufir_data1,ufir_data2=draw_data(ufir_data)
true_data1,true_data2=draw_data(true_data)
print(str(mean(kluda_data1,true_data1))+"   "+str(rmse(kluda_data1,true_data1)))
print(str(mean(ufir_data1,true_data1))+"   "+str(rmse(ufir_data1,true_data1)))
print(str(mean(kluda_data2,true_data2))+"   "+str(rmse(kluda_data2,true_data2)))
print(str(mean(ufir_data2,true_data2))+"   "+str(rmse(ufir_data2,true_data2)))
ax2.plot(x_time[::20], kluda_data1[::20], '*', color='blue', alpha=0.8, linewidth=1.5, label='KUFIR2')
ax2.scatter(x_time[::20], ufir_data1[::20],  marker='o', facecolors='none',edgecolors='r', s=50, label='TUFIR2')
ax2.plot(x_time[::20], true_data1[::20], color='green',  alpha=0.8, linewidth=1.5, label='TRUE')
ax2.legend(ncol = 3)

plt.subplot(3,1,3)
kluda_data =open(r'D:\vs项目\KLUDA\result\kluda30.txt','r')
ufir_data =open(r'D:\vs项目\KLUDA\result\ufir30.txt','r')
true_data =open(r'D:\vs项目\KLUDA\result\true30.txt','r')
kluda_data1,kluda_data2 = draw_data(kluda_data)
ufir_data1,ufir_data2=draw_data(ufir_data)
true_data1,true_data2=draw_data(true_data)
print(str(mean(kluda_data1,true_data1))+"   "+str(rmse(kluda_data1,true_data1)))
print(str(mean(ufir_data1,true_data1))+"   "+str(rmse(ufir_data1,true_data1)))
print(str(mean(kluda_data2,true_data2))+"   "+str(rmse(kluda_data2,true_data2)))
print(str(mean(ufir_data2,true_data2))+"   "+str(rmse(ufir_data2,true_data2)))
ax3.plot(x_time[::20], kluda_data1[::20], '*', color='blue', alpha=0.8, linewidth=1.5, label='KUFIR3')
ax3.scatter(x_time[::20], ufir_data1[::20],  marker='o', facecolors='none',edgecolors='r', s=50, label='TUFIR3')
ax3.plot(x_time[::20], true_data1[::20], color='green',  alpha=0.8, linewidth=1.5, label='TRUE')
ax3.legend(ncol = 3)
ax3.set_xlabel('Times (s)')
fig.subplots_adjust(left=0.15, right=0.95, top=0.95, bottom=0.08)  # 增加左边距
plt.savefig("state1.svg")
plt.show()







