from math import sqrt
import matplotlib.pyplot as plt
from matplotlib import transforms
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure
import matplotlib.patches as patches

x = []
y = []

with open("SomeText.txt", "r") as f:
    for line in f:
        i = 0
        while(line[i] != ' '):
            i += 1
        x.append(float(line[:i]))
        y.append(float(line[i+1:len(line)-1]))

fig,ax=plt.subplots()

for i in range(len(x)):
    rect = patches.Rectangle((x[i],y[i]), 1, 1, edgecolor='black', facecolor = 'white')
    ax.add_patch(rect)

ax.axis('equal')

x1 = []
y1 = []
x2 = []
y2 = []

with open("SomeText2.txt", "r") as f:
    for num, line in enumerate(f):
        if(num % 2 == 0):
            i = 0
            while(line[i] != ' '):
                i += 1
            x1.append(float(line[:i]))
            y1.append(float(line[i+1:len(line)-1]))
        else:
            i = 0
            while(line[i] != ' '):
                i += 1
            x2.append(float(line[:i]))
            y2.append(float(line[i+1:len(line)-1]))

for i in range(len(x1)):
    plt.plot((x1[i]+0.5, x2[i]+0.5), (y1[i]-0.2, y2[i]+0.2), color = 'black', lw = 0.5)
  
ax.axis('equal')

plt.show()


