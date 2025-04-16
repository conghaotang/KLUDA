import matplotlib.pyplot as plt			# 导入模块
import numpy as np
import math

plt.rcParams['font.sans-serif']=['Times New Roman']
plt.rcParams['axes.unicode_minus']=False
plt.rcParams['font.size']=10
plt.figure(figsize=(5, 4))

x=[2,5,10,15,20,25,30,35]
y1 = [0.898655,0.722074, 0.72419,0.718794,0.723757, 0.726591,0.714855, 0.720134]
y2 = [ 8.40698, 9.51191,11.6554, 13.8734,15.9634,18.0089,20.1018,22.3258]
y3 = [0.285312,0.287322,0.283681,0.285181,0.287136,0.285423,0.285359,0.287735]


plt.plot(x,y1,'blue',label='KUFIR')
plt.plot(x,y2,'red',label='TUFIR')
plt.plot(x,y3,'green',label='KF')

plt.legend(loc="upper left")
plt.xlabel('N')
plt.ylabel('Computation Time (s)')
plt.legend(ncol = 3)
plt.subplots_adjust(left=0.15, right=0.95, top=0.95, bottom=0.13)  # 增加左边距
plt.savefig("Computation Time.svg")
plt.show()
