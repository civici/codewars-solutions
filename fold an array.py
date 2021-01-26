def foldArray(array, runs):
    
    newarray = []
    for integer in array:
        newarray.append(integer)

    for i in range(runs):
        temp = []
        for j in range(int(len(newarray) / 2)):
            temp.append(newarray[j] + newarray[len(newarray) - 1 - j])
        if len(newarray) % 2 == 1:
            temp.append(newarray[int(len(newarray) / 2)])
        newarray.clear()
        for integer in temp:
            newarray.append(integer)

    return newarray
