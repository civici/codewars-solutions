# https://www.codewars.com/kata/5626b561280a42ecc50000d1/train/python

def sum_dig_pow(a, b):
    sum = []
    for i in range(a, b + 1):
        digitsBuffer = i
        digitsCounter = 1  
        while digitsBuffer >= 10:
            digitsBuffer //= 10
            digitsCounter += 1
        tempsum = 0
        for j in range(1, digitsCounter + 1):
            tempsum += ( ( i // ( 10 ** ( digitsCounter - j ) ) ) % 10 ) ** j
        if tempsum == i: sum.append(tempsum)

    return sum

x = sum_dig_pow(88, 89)
print(x)
