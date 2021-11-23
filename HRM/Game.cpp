
#include <iostream>
#include <fstream>
#include "Game.h"

using namespace std;

Space *Inbox, *Outbox, *Floor;
Robot robot;
int Game_status;
int command_size;



Space::Space(int init_size) {
	size = init_size;
	head = 0;
	tail = 0;
	value = new int[init_size];
	status = new char[init_size];
	for (int i = 0; i < init_size; i++) {
		status[i] = '\0';
	}

	cout << "A Space of size " << size << " is created.\n";	//调试用
}

Space::~Space() {
	delete value;
	delete status;

	cout << "A Space of size " << size << " is deleted.\n";	//调试用
}

void put(Space* A, int a, int pos) {
	A->value[pos] = a;
	A->status[pos] = 'f';
}

void push(Space* A, int a) {
	A->value[A->tail] = a;
	A->status[A->tail] = 'f';
	A->tail++;
}

int pop_head(Space* A) {
	int value = A->value[A->head];
	A->status[A->head] = 'e';
	A->head++;
	return value;
}

int read(Space* A, int pos) {
	return A->value[pos];
}

Command::Command(){
	next = -1;
}

Robot::Robot() {
	status = 'e';
}
