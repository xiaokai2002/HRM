#ifndef GAME_H
#define GAME_H


void play();


struct Space {
	int *value;
	char *status;	
	int size;
	int head, tail;

	Space(int init_size); 
	~Space();
};

void put(Space* A, int a, int pos);
void push(Space* A, int a);
int pop_head(Space* A);
int read(Space* A, int pos);

struct Command {
	char com[2];
	int next;
	
	Command();
};



struct Robot {
	int value;
	char status;

	Robot();
};

#endif
