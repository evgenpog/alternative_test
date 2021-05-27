def sort():

    coords = []

    with open("SomeText.txt", "r") as f:
        for line in f:
            coords.append([float(line[line.find(' ')+1:line.find('|')]),float(line[:line.find(' ')]),line[line.find('|')+1:len(line)-1]])

    coords.sort()

    with open("SortedCoordsAndDims.txt", "w") as f:
        for i in range(len(coords)-1):
            f.writelines(str(coords[i][1])+' '+str(coords[i][0])+'|'+str(coords[i][2])+'\n')
            if(abs(coords[i+1][0] - coords[i][0]) > 1):
                f.writelines('\n')
        f.writelines(str(coords[-1][1])+' '+str(coords[-1][0])+'|'+str(coords[-1][2])+'\n')   
        f.writelines('\n')
    
        
