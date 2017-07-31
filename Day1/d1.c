#include <stdio.h>
#include <string.h>

int crossed (int add_one, int add_two){
	if ((add_one < 0) && +(add_one + add_two > 0)){
		
		printf("********crddddxxxddddxxxxxosseeeesddddeeeeeeeed %d %d\n", add_one, add_two);
		return 1;
	}
	return 0;
}


int main (int argc, char**argv){
	// int score [4]; //0 north, 1 right, 2 left, 3 south
	// int compass =0; 
	char filename[50];
	strncpy (filename, argv[1], 50);

	FILE *fp;
	fp = fopen(argv[1], "r+");

	if (fp == NULL ) {
		fprintf(stderr, "could not open %s for writting.\n",filename);
		return (1);
	}
	printf ("Opening file... %s\n",filename );

	char curr;
	int steps;
	int horizontal = 0;
	int vertical = 0;
	char facing = 'N';
	while ( (curr = fgetc(fp)) != EOF){
		fscanf (fp, "%d", &steps);
		if (curr == (char)32){ //space
			continue;
		}
		if (curr == (char)44){ //coma
			continue;
		}
		printf ("curr is: %d, %c |",curr, curr);
		printf ("steps is %d \n", steps);

		if ((curr == 'R') && (facing == 'N')){
			facing = 'R';
			crossed(horizontal, steps);
			horizontal += steps;
		}else if ((curr == 'R') && (facing == 'R')){
			facing = 'D';
			crossed(vertical, steps);

			vertical -= steps;
		}else if ((curr == 'R') && (facing == 'D')){
			facing = 'L';
			crossed(horizontal, steps);

			horizontal -= steps;
		}else if ((curr == 'R') && (facing == 'L')){
			facing = 'N';
			crossed(vertical, steps);
			vertical += steps;
		}

		if ((curr == 'L') && (facing == 'N')){
			facing = 'L';
			crossed(horizontal, steps);
			horizontal -= steps;
		}else if ((curr == 'L') && (facing == 'R')){
			facing = 'N';
			crossed(vertical, steps);
			vertical += steps;
		}else if ((curr == 'L') && (facing == 'D')){
			facing = 'R';
			crossed(horizontal, steps);
			horizontal += steps;
		}else if ((curr == 'L') && (facing == 'L')){
			facing = 'D';
			crossed(vertical, steps);

			vertical -= steps;
		}
		printf("vertical:%d horizontal:%d\n ", vertical, horizontal);

	}
	printf("FINAL vertical:%d horizontal:%d\n ", vertical, horizontal);




}