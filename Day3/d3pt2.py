#!/usr/bin/env python3

import sys

def test_group(num0, num1, num2):
    if ((num0 + num1) > num2):
        if ((num0 + num2 ) > num1):
            if ((num1 + num2) > num0):
                return 1
            else:
                return 0
        else:
            return 0
    else:
        return 0

def main():
    data = []
    try:
        with open ("input.txt", mode = "r") as input_file:
            i = 0
            for num in input_file:
                buff = []
                for ch in num.split():
                    buff.append(int(ch))
                data.append(buff)

    except IOError:
        print ("No file found :(" )

    counter =0
    group = []
    for i in range (0, len(data[0])):
        for j in range (0, len(data)):
            group.append(data[j][i])
            if (len(group) == 3):
                counter += test_group(group[0], group[1], group[2])
                group = []
    print ("Total triangles", counter)

if __name__ == "__main__":
    main()