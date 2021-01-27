"""
credits to https://www.codewars.com/users/sahglie thank you !!!

https://www.codewars.com/kata/52ea928a1ef5cfec800003ee/train/python

"""


def ip_to_int32(ip : str):
    
    tempstr : str = ""
    index : int = 0
    num = 0
    for i in range(len(ip)):
        if ip[i] == '.':
            num += int(tempstr) * pow(2, 8 * (3 - index))
            tempstr = ""
            index += 1
        else:
            tempstr += ip[i]
            if i == len(ip) - 1: num += int(tempstr) * pow(2, 8 * (3 - index))
    
    return num

