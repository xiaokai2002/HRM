#include "Command.h"
#include "Game.h"
using namespace std;



extern Space *Inbox, *Outbox, *Floor;
extern Robot robot;	
extern int Game_status;
extern int command_size;


void inbox() {
	if (Inbox->head == Inbox->tail) {
		Game_status = 0;
		return;
	}
	else {
		robot.value = pop_head(Inbox);
		robot.status = 'f';
		return;
	}
}

void outbox() {
	if ('e' == robot.status) {
		Game_status = -1;
		return;
	}
	else {
		push(Outbox, robot.value);
		robot.status = 'e';
		return;
	}
}

void add(int X) {
	if (X > Floor->size) {
		Game_status = -1;
	}
	else if ('e' == robot.status || 'e' == Floor->value[X]) {
		Game_status = -1;
	}
	else {
		robot.value += Floor->value[X];
	}	
}

void sub(int X) {
	if (X > Floor->size) {
		Game_status = -1;
	}
	else if ('e' == robot.status || 'e' == Floor->value[X]) {
		Game_status = -1;
	}
	else {
		robot.value -= Floor->value[X];
	}
}

void copyto(int X) {
	if (X > Floor->size || 'e' == robot.status) {
		Game_status = -1;
	}
	else {
		Floor->value[X] = robot.value;
	}
}

void copyfrom(int X) {
	if (X > Floor->size) {			
		Game_status = -1;
	}
	else if ('e' == Floor->status[X]) {
		Game_status = -1;
	}
	else {
		Floor->value[X] = robot.value;
	}
}

void jump(int X){
	if (X > Floor->size) {
		Game_status = -1;
	}
}

void jumpifzero(int X) {
	if (X > Floor->size || 'e' == robot.status) {
		Game_status = -1;
	}
	else if (0 == robot.value) {
		jump(X);
	}
}

