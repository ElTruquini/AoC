#!/usr/bin/env python3

import argparse
import sys
import struct

do_nothing_flag = False
curr = 5

def is_valid_move (step):
    global curr
    print ("is_valid_move - step:%s | curr:%s" % (step, curr))
    if ( (curr == 1 or curr == 2 or curr == 4 or curr == 5 or curr == 9) and (step == 'U' )):
        do_nothing_flag = True
        return False
    if ( (curr == 1 or curr == 2 or curr == 5 or curr == 'A' or curr == 'D') and (step == 'L' )):
        do_nothing_flag = True
        return False
    if ( (curr == 1 or curr == 4 or curr == 9 or curr == 'C' or curr == 'D') and (step == 'R' )):
        do_nothing_flag = True
        return False
    if ( (curr == 5 or curr == 'A' or curr == 'D' or curr == 'C' or curr == 9) and (step == 'D' )):
        do_nothing_flag = True
        return False
    return True

def move (step):
    global curr
    print ("move - curr", curr)
    print ("move - step", step)
    if ( curr == 1 and step == 'D' ):
        return 3

    if ( curr == 2 and step == 'D' ):
        return 6
    if ( curr == 2 and step == 'R' ):
        return 3

    if ( curr == 3 and step == 'D' ):
        return 7
    if ( curr == 3 and step == 'L' ):
        return 2
    if ( curr == 3 and step == 'R' ):
        return 4
    if ( curr == 3 and step == 'U' ):
        return 1                                    
    
    if ( curr == 4 and step == 'D' ):
        return 8
    if ( curr == 4 and step == 'L' ):
        return 3

    if ( curr == 5 and step == 'R' ):
        return 6
         
    if ( curr == 6 and step == 'D' ):
        return 'A'
    if ( curr == 6 and step == 'L' ):
        return 5
    if ( curr == 6 and step == 'R' ):
        return 7
    if ( curr == 6 and step == 'U' ):
        return 2

    if ( curr == 7 and step == 'D' ):
        return 'B'
    if ( curr == 7 and step == 'L' ):
        return 6
    if ( curr == 7 and step == 'R' ):
        return 8
    if ( curr == 7 and step == 'U' ): 
        return 3

    if ( curr == 8 and step == 'D' ):
        return 'C'
    if ( curr == 8 and step == 'L' ):
        return 7
    if ( curr == 8 and step == 'R' ):
        return 9
    if ( curr == 8 and step == 'U' ):
        return 4                                  
        
    if ( curr == 9 and step == 'L' ):
        return 8

    if ( curr == 'A' and step == 'U' ):
        return 6
    if ( curr == 'A' and step == 'R' ):
        return 'B'

    if ( curr == 'B' and step == 'D' ):
        return 'D'
    if ( curr == 'B' and step == 'L' ):
        return 'A'
    if ( curr == 'B' and step == 'R' ):
        return 'C'
    if ( curr == 'B' and step == 'U' ):
        return 7      

    if ( curr == 'C' and step == 'U' ):
        return 8
    if ( curr == 'C' and step == 'L' ):
        return 'B'


    if ( curr == 'D' and step == 'U' ):
        return 'B'


    return -1  #should not be reached

def main():
    input_file = sys.argv[1]
    data = []
    try:
        with open(input_file, mode = "r") as input_file:
            for line in input_file:
                data.append(line.strip())

    except IOError:
        print ("Error: File does not appear to exist.")
        return 0


    global curr
    global do_nothing_flag
    code = []

    while (len(data)>0):
        do_nothing_flag = False
        instruction = data.pop(0)
        print ("instruction ", instruction)

        for step in instruction:
            print("Loop - step:", step)

            if (is_valid_move(step)):
                curr = move(step)
                if (curr == -1):
                    sys.exit("curr is -1") 
        print("\n APPENDING to code,", curr)
        code.append(curr)   
    print ("Final code", code)

if __name__ == "__main__":
    main()