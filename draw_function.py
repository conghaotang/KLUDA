import matplotlib.pyplot as plt			# 导入模块
import numpy as np
import math

plt.rcParams['font.sans-serif']=['Calibri']
plt.rcParams['axes.unicode_minus']=False
plt.rcParams['font.size']=10

x = np.arange(-3,3,0.01)
y1 = x*x*0.5
bond=0.6

y2=[]
for i in x:
    if i<=0:
        if abs(i)<bond:
            y2.append(0)
        if abs(i)>=bond:
            y2.append((abs(i)-bond))
    if i>0:
        symbol=1
        if abs(i)<bond:
            y2.append(0)
        if abs(i)>=bond:
            y2.append((abs(i)-bond))

fig, (ax1) = plt.subplots(1, 1, figsize=(5, 4),dpi=200)

ax1.plot(x, y1,  color='red', alpha=0.8, linewidth=0.8, label='L2-loss')
ax1.plot(x, y2,  color='blue', alpha=0.8, linewidth=0.8, label='eps-insensitive')
ax1.set_xlim(-3,3)
ax1.set_ylim(0,4.5)
ax1.set_xlabel("x")
ax1.set_ylabel("I(x)")
ax1.tick_params(axis='both', direction='in', top=True, right=True)
#ax1.legend(frameon=False, fontsize=10, loc='upper right',handletextpad=0.5, labelspacing=1)
ax1.set_title('Optimal Loss Function', fontsize=10)


# 显示图例，设置图例位置并往左边移动一点
legend = ax1.legend(frameon=False, fontsize=10, loc='upper right',
                    bbox_to_anchor=(0.95, 1), handletextpad=2, labelspacing=1)


# 取消图例中的颜色线条（标记）
for handle in legend.legendHandles:
    handle.set_visible(False)

# 设置图例文字颜色
texts = legend.get_texts()
texts[0].set_color('red')
texts[1].set_color('blue')
plt.savefig('Optimal Loss Function.svg', format='svg', bbox_inches='tight')
plt.show()
