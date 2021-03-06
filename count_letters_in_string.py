# https://www.codewars.com/kata/5808ff71c7cfa1c6aa00006d

def letter_count(s):
    letters : list = []
    counts  : list = []

    for i in range(len(s)):
        found : bool = False

        for j in range(len(letters)):
            if s[i] == letters[j]:
                counts[j] += 1
                found = True

        if found:
            continue

        letters.append(s[i])
        counts.append(1)

    for j in range(len(letters)):
        min : int = ord("z") + 1
        minindex : int = 0
        for i in range(j, len(letters)):
            if ord(letters[i]) < min:
                min = ord(letters[i])
                minindex = i
        temp = letters[j]
        letters[j] = letters[minindex]
        letters[minindex] = temp

        tempindex = counts[j]
        counts[j] = counts[minindex]
        counts[minindex] = tempindex

    couldntfindname : dict = {}
    for i in range(len(letters)):
        couldntfindname[letters[i]] = counts[i]

    return couldntfindname