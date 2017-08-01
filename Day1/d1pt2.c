#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct step steppy;  //used as an abbreviation for the type struct step..

struct step{
    int x;
    int y;
    steppy* next;

};

void *emalloc(size_t n) {
	void *p;

	p = malloc(n);
	if (p == NULL) {
		fprintf(stderr, "malloc of %zu bytes failed", n);
		exit(1);
	}
	return p;
}
 


steppy* new_step_xy(int x, int y) {
	steppy* temp;
	temp = (steppy *) emalloc(sizeof(steppy));
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	return temp;

}

steppy *add_list(steppy* list, steppy* cv){
	printf("add_list - Adding node x:%d, y:%d\n", cv->x, cv->y);
	steppy *curr;
	if (list == NULL){
		cv->next = NULL;
		return cv;
	}
	for (curr = list; curr->next != NULL; curr = curr->next);
	curr->next = cv;
	cv->next = NULL;
	return list;
}


steppy *find (steppy* list, int x, int y){
	steppy* curr = list;
	for ( ; curr != NULL ; curr = curr->next){
		if ((curr->x == x) && (curr->y == y)){
			printf("\n*****Item found***** ");
			return curr;
		}
	}
	printf("NOT found - ");

	return NULL;
}

void print_find (steppy *list, int x, int y){
	steppy *foo =find(list, x, y);
	if (foo == NULL){
		//printf("NOT FOUND! \n");
	}else{
		printf("\nITEM at x:%d y:%d \n", foo->x, foo->y);
		exit(0);
		
	}

}

steppy *add_steps (steppy *list, int steps, steppy *position, int mode){
	for (int i =1 ; i <= steps ; i++){
		if (mode == 0){ // (curr == 'R') && (facing == 'N')
			//printf("i:%d | position->x:%d | position->x+i:%d \n", i, position->x, (position->x)+i);
			steppy *temp = new_step_xy((position->x)+i, position->y);
			print_find(list,(position->x)+i, position->y);
			list = add_list(list, temp);

		}else if (mode == 1){ //((curr == 'R') && (facing == 'D')){
			steppy *temp = new_step_xy((position->x)-i, position->y);
			print_find(list,(position->x)-i, position->y);
			list = add_list(list, temp);

		}else if (mode ==2){ //((curr == 'R') && (facing == 'R'))
			steppy *temp = new_step_xy((position->x), position->y-i);
			print_find(list,(position->x), (position->y)-i);
			list = add_list(list, temp);

		}else if (mode ==3){ //(curr == 'R') && (facing == 'L')){
			steppy *temp = new_step_xy((position->x), position->y+i);
			print_find(list,(position->x), (position->y)+i);
			list = add_list(list, temp);

		}else if (mode ==4){ //(curr == 'L') && (facing == 'N')
			steppy *temp = new_step_xy((position->x)-i, position->y);
			print_find(list,(position->x)-i, position->y);
			list = add_list(list, temp);

		}
		else if (mode ==5){ //((curr == 'L') && (facing == 'D'))
			steppy *temp = new_step_xy((position->x)+i, position->y);
			print_find(list,(position->x)+i, position->y);
			list = add_list(list, temp);

		}
		else if (mode ==6){ //((curr == 'L') && (facing == 'R'))
			steppy *temp = new_step_xy((position->x), position->y+i);
			print_find(list,(position->x), (position->y)+i);
			list = add_list(list, temp);

		}
		else if (mode ==7){// ((curr == 'L') && (facing == 'L')
			steppy *temp = new_step_xy((position->x), (position->y)-i);
			print_find(list,(position->x), (position->y)-i);
			list = add_list(list, temp);

		}
	}
	return list;

}

void print_list (steppy *list){
	for (steppy *curr = list ; curr != NULL ; curr = curr->next){
		printf("Node x:%d - y:%d \n", curr->x, curr->y);
	}
}


int main (int argc, char**argv){
	// int score [4]; //0 north, 1 right, 2 left, 3 south
	// int compass =0; 
	char filename[50];
	strncpy (filename, argv[1], 50);

	FILE *fp;
	fp = fopen(argv[1], "r");

	if (fp == NULL ) {
		fprintf(stderr, "could not open %s for writting.\n",filename);
		return (1);
	}
	printf ("Opening file... %s\n",filename );

	char curr;
	int steps;
	char facing = 'N';

	steppy *foo;
	steppy *visited = new_step_xy(0,0);
	steppy *position = new_step_xy(0,0);

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

		printf("LOOP position.x:%d position.y:%d\n ", position->x, position->y);


		if ((curr == 'R') && (facing == 'N')){
			facing = 'R';
			visited = add_steps(visited, steps, position, 0);

			position->x += steps;

		}else if ((curr == 'R') && (facing == 'D')){
			facing = 'L';
			visited = add_steps(visited, steps, position, 1);
			position->x -= steps;
		}else if ((curr == 'R') && (facing == 'R')){
			facing = 'D';
			visited = add_steps(visited, steps, position, 2);
			position->y -= steps;
		}else if ((curr == 'R') && (facing == 'L')){
			facing = 'N';
			visited = add_steps(visited, steps, position, 3);
			position->y += steps;
		}

		if ((curr == 'L') && (facing == 'N')){
			facing = 'L';
			visited = add_steps(visited, steps, position, 4);

			position->x -= steps;
		}else if ((curr == 'L') && (facing == 'D')){
			facing = 'R';
			visited = add_steps(visited, steps, position, 5);

			position->x += steps;
		}else if ((curr == 'L') && (facing == 'R')){
			facing = 'N';
			visited = add_steps(visited, steps, position, 6);

			position->y += steps;
		}else if ((curr == 'L') && (facing == 'L')){
			facing = 'D';
			visited = add_steps(visited, steps, position, 7);

			position->y -= steps;
		}





	}
	printf("\nPrinting list:\n");
	print_list(visited);
	printf("\n FINAL position.y:%d position.x:%d\n ", position->y, position->x);

	/*
	int x =-9;
	int y=-3;
	foo =find(visited, x, y);
	if (foo == NULL){
		printf("NOT FOUND! \n");
	}else{
		printf("Find x:%d y:%d \n", foo->x, foo->y);
		
	}

	*/



}