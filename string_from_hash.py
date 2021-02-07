"""
credits to https://www.codewars.com/users/jhoffner
https://www.codewars.com/kata/51c7d8268a35b6b8b40002f2
"""

def solution(pairs : dict):
    return "".join([str(pair) + " = " + str(pairs[pair]) + "," for pair in pairs])[0:-1]

