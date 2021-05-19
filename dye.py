import matplotlib.pyplot as plt
from matplotlib import transforms
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches

x = []
y = []
c = []

with open("x_y_color.txt", "r") as f:#считывание файла
    for line in f:
        x.append(int(line[:3]))
        y.append(int(line[7:10]))
        c.append(line[16:22])
      
fig,ax=plt.subplots()

for i in range(len(x)):
    rect = patches.Rectangle((x[i],y[i]), 1, 1, edgecolor='black', facecolor = '#' + c[i])
    ax.add_patch(rect)

ax.axis('equal')

plt.show()



