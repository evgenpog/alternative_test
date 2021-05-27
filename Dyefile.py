
def Dye(key):

    razm = []

    with open("SortedCoordsAndDims.txt", "r") as r, open('ColoredCoords.txt', 'w') as w:       
        for line in r:
            if(len(line) == 1):
                if max(razm) != 1:
                    razm[:] = [x - 1 for x in razm]
                if(key == 'y'):
                    for i in range(len(razm)):
                        if(len(str(hex(255 - ((razm[i]) * 255 // (max(razm)))))[2:]) < 2):
                            color = color = '#ff' + '0' + str(hex(255 - ((razm[i]) * 255 // (max(razm)))))[2:] + '0' + str(hex(255 - ((razm[i]) * 255 // (max(razm)))))[2:] 
                        else:
                            color = '#ff' + str(hex(255 - ((razm[i]) * 255 // (max(razm)))))[2:] + str(hex(255 - ((razm[i]) * 255 // (max(razm)))))[2:]
                        if(len(color) < 7):
                            color = color + '0' * (7 - len(color))
                        w.writelines(color + '\n')
                w.writelines(line)
                razm.clear()
            else:
                razm.append(int(line[line.find('|') + 1:len(line)-1]))

