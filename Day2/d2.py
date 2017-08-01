#!/usr/bin/env python3

import argparse
import sys
import struct

do_nothing_flag = False
curr = 5

def is_valid_move (step):
	global curr
	if ( (curr == 1 or curr == 2 or curr == 3) and (step == 'U' )):
		do_nothing_flag = True
		print ("1,2,3 and U - ignore")
		return False
	if ( (curr == 1 or curr == 4 or curr == 7) and (step == 'L' )):
		do_nothing_flag = True
		print ("1,4,7 and L - ignore")
		return False
	if ( (curr == 3 or curr == 6 or curr == 9) and (step == 'R' )):
		do_nothing_flag = True
		print ("3,6,9 and R - ignore")
		return False
	if ( (curr == 7 or curr == 8 or curr == 9) and (step == 'D' )):
		do_nothing_flag = True
		print ("7,8,9 and D - ignore")
		return False
	return True

def move (step):
	global curr
	print ("move - curr", curr)
	print ("move - step", step)
	if ( step == 'U' ):
		return curr - 3
	if ( step == 'D'):
		return curr + 3
	if ( step == 'L'):
		return curr - 1
	if ( step == 'R'):
		return curr + 1

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
			print("step:", step)

			if (is_valid_move(step)):
				curr = move(step)
		print("\n appending to code,", curr)
		code.append(curr)	
	print ("Final code", code)

if __name__ == "__main__":
	main()