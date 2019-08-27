
import numpy as np
import random

array = np.zeros((10,10), dtype='int32');
fleet = [5, 4, 3, 3, 2];
rows = [x for x in range(10)];
cols = [x for x in range(10)];
orientations = ['h', 'v'];

lst = []
lst_list = []
lst2 = []
for i,j in enumerate(fleet):
    lst_temp = []
    while True:
        row = random.choice(rows)
        col = random.choice(cols)
        orientation = random.choice(orientations);
        count = 0
        if orientation == 'v':
            if (row + fleet[i] <= 10):
                for k in range(j):
                    if ([row + k, col] not in lst2) and \
                       ([row, col] not in lst2):
                        count += 1
        elif orientation == 'h':
            if (col + fleet[i] <= 10):
                count = 0
                for k in range(j):
                    if ([row, col + k] not in lst2) and \
                       ([row, col] not in lst2):
                        count += 1
        if count == j:
            break
    for l in range(j):
        if orientation == 'v':
            lst.append([row, col])
            lst_temp.append([row, col])
            array[row][col] = 1
            row += 1
        if orientation == 'h':
            array[row][col] = 1
            lst.append([row, col])
            lst_temp.append([row, col])
            col += 1
    lst_list.append(lst_temp)

    for i, j in enumerate(lst_list):
        for k in j:
            x = k[0]
            y = k[1]
            if orientation == 'v':
                if i == 0:
                    lst2.append([x - 1, y])
                if i == len(lst_list) - 1:
                    lst2.append([x + 1, y])
                lst2.append([x, y])
                lst2.append([x, y - 1])
                lst2.append([x, y + 1])

            if orientation == 'h':
                lst2.append(k)
                if i == 0:
                    lst2.append([x, y - 1])
                if i == len(lst_list) - 1:
                    lst2.append([x, y + 1])
                lst2.append([x, y])
                lst2.append([x - 1, y])
                lst2.append([x + 1, y])

print(array)


        

    
