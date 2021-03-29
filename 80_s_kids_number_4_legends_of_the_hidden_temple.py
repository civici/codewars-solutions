# https://www.codewars.com/kata/56648a2e2c464b8c030000bf/train/python

def mark_spot(n):

    if type(n) != int or n % 2 != 1 or n < 1:
        return "?"

    maxLineLen = 2 * n - 1
    middleLineIndex = int(n / 2) + 1
    finalStr = ""

    for i in range(1, n + 1):
        if i > middleLineIndex:
            i = middleLineIndex - (i - middleLineIndex)
        outsideSpaces = (i - 1) * 2
        firstPart = " " * outsideSpaces
        middlePart = (maxLineLen - (outsideSpaces * 2) - 2) * " "
        if i == middleLineIndex:
            finalStr += firstPart + "X"
        else:
            finalStr += firstPart + "X" + middlePart + "X"
        finalStr += "\n"

    return finalStr

