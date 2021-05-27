from math import sqrt
import matplotlib.pyplot as plt
from matplotlib import transforms
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure
import matplotlib.patches as patches
import matplotlib.cm as cm
import Dyefile
import Sortfile

razm = []
x = []
y = []
x1 = []
y1 = []
x2 = []
y2 = []
color = []
x_j = []
y_j = []

print('Покраска диаграмм по размерностям? (y/n)')
key_color = str(input())
print('Выделение диаграмм с максимальными размерностями (y/n)')
key_max = str(input())
print('Выделение диаграмм жадной последовательности? (y/n)')
key_zhadn = str(input())
print('Отрисовка ребер? (y/n)')
key_rebra = str(input())


fl = 15
i = 0

Sortfile.sort()
Dyefile.Dye(key_color)

with open("SortedCoordsAndDims.txt", "r") as f:
    for line in f:
        if len(line) > 1:
            x.append(float(line[:line.find(' ')]))
            y.append(float(line[line.find(' ')+1:line.find('|')]))
            razm.append(line[line.find('|')+1:len(line)-1])
            
with open("Jadn.txt", "r") as f:
    for line in f:
        if len(line) > 1:
            x_j.append(float(line[:line.find(' ')]))
            y_j.append(float(line[line.find(' ')+1:len(line)-1]))


with open("SomeText2.txt", "r") as f:
    for num, line in enumerate(f):
        if len(line) > 1:
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

with open('ColoredCoords.txt', 'r') as f:   
    for line in f:
        if(len(line)>1):
            color.append(line[:7])

fig,ax=plt.subplots()

for i in range(len(x)):
    if(key_color == 'y'):
            rect = patches.Rectangle((x[i],y[i]), 1, 1, edgecolor='black', facecolor = color[i], lw = 0.1)
            ax.add_patch(rect)
    if(key_max == 'y'):
        if(color[i] == "#ff0000"):
            rect = patches.Rectangle((x[i],y[i]), 1, 1, edgecolor='black', facecolor = 'yellow', lw = 0.3)
            ax.add_patch(rect)
    if(key_max == 'n' and key_color == 'n'):
        rect = patches.Rectangle((x[i],y[i]), 1, 1, edgecolor='black', facecolor = 'white', lw = 0.1)
        ax.add_patch(rect)
    #ax.text(x[i]+0.5, y[i]+0.5, razm[i], fontsize = 6)
    #plt.pause(0.001)
    #ax.axis('equal')

if(key_zhadn == 'y'):
    for i in range(len(x_j)):
        l1 = [x_j[i], x_j[i], x_j[i]+1]
        l2 = [y_j[i], y_j[i]+1, y_j[i]]
        ax.fill(l1, l2, color = 'black')
        
        

if(key_rebra == 'y'):
    for i in range(len(x1)):
        plt.plot((x1[i]+0.5, x2[i]+0.5), (y1[i]-0.2, y2[i]+0.2), color = 'black', lw = 0.1)
        #plt.pause(0.001)
        #ax.axis('equal')

ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['left'].set_visible(False)
ax.spines['bottom'].set_visible(False)
plt.axis('off')

#ax.axis('scaled')
ax.axis('equal')
plt.savefig("Graph.png", dpi=900)

plt.show()



