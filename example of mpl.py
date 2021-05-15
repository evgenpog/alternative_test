'''
 Написать программу для визуализации двумерных,
 трехмерных и четырехмерных таблиц Юнга в виде проекции графа Паскаля на плоскость.
 Вершинами данного графа являются клетки таблиц. Ребра соединяют соседние клетки.
'''

from math import sqrt
import matplotlib.pyplot as plt
from matplotlib import transforms
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure

x = []
y = []
with open("tab1.txt", "r") as f:#считывание файла
    for line in f:
        x.append(line[:2])
        y.append(line[7:9])

fig,ax=plt.subplots()

ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['left'].set_visible(False)
ax.spines['bottom'].set_visible(False)
plt.axis('off')#скрывание осей и их значения

radius = 0.5
numsize = 1#параметры 2/14

for i in range(len(x)):
    circle = plt.Circle(((int(y[i])-int(x[i])), -(int(x[i])+int(y[i]))), radius, color='black', fill=False, lw=0.1)#круги
    ax.text((int(y[i])-int(x[i]))-0.1*(len(str(i+1))),-(int(y[i])+int(x[i]))-0.1, i+1, fontsize = numsize)#цифры
    ax.add_patch(circle)
    if(int(x[i]) != 0):
        plt.plot(((int(y[i])-int(x[i]))+sqrt(radius*radius/2), (int(y[i])-int(x[i]))+1-sqrt(radius*radius/2)),
             (-(int(y[i])+int(x[i]))+sqrt(radius*radius/2), -(int(x[i])+int(y[i]))-sqrt(radius*radius/2)+1), color = 'black', lw=0.1)#линии
    if(int(y[i]) != 0):
        plt.plot(((int(y[i])-int(x[i]))-sqrt(radius*radius/2), (int(y[i])-int(x[i]))-1+sqrt(radius*radius/2)),
             (-(int(y[i])+int(x[i])-sqrt(radius*radius/2)), -(int(x[i])+int(y[i]))-sqrt(radius*radius/2)+1), color = 'black', lw=0.1)
    #plt.pause(0.001)
ax.axis('equal')

#plt.rcParams['text.usetex'] = True
#plt.rcParams['font.size'] = 18000
#figure(figsize=(5,5))   
plt.savefig('saved_graf2D.png', dpi = 675)
img = plt.imread('saved_graf2D.png')
ax.imshow(img)#пикча пнг



plt.show()



