#!/usr/bin/env python3

import sys

def main():
    data = []
    try:
        with open ("input.txt", mode = "r") as input_file:
            i = 0
            for line in input_file:
                buff = []
                for ch in line.split():
                    buff.append(int(ch))
                data.append(buff)

    except IOError:
        print ("No file :(" )

    counter =0
    print(data)
    for line in data:
        if ((line[0]+line[1]) > line[2]):
            if ((line[0]+line[2]) > line[1]):
                if ((line[1]+line[2]) > line[0]):
                    counter += 1
        else:
            print ("Not triangle", line)

    print ("Total triangles", counter)

if __name__ == "__main__":
    main()