
razm = []

with open("2Dgraph_try_42.txt", "r") as r, open('2Dgraph_color_42.txt', 'w') as w:
    for line in r:
        if(line[0] == 'L'):
            w.writelines(line)
        elif(len(line) == 1):
            if max(razm) != 1:
                    razm[:] = [x - 1 for x in razm]
            for i in range(len(razm)):
                color = '#ff'+str(hex(65535 - ((razm[i]) * 65535 // (max(razm)))))[2:]
                if(len(color) < 7):
                    color = color + '0' * (7 - len(color))
                w.writelines(color + '\n')
            w.writelines(line)
            razm.clear()
        else:
            razm.append(int(line[line.find('|') + 1]))

