#include "qeues.h"

qeues_with_Array::qeues_with_Array() {
	std::cout << "enter the size of your Qeue : ";
	std::cin >> SIZE;
	Arr = new int[SIZE];
}

qeues_with_Array::~qeues_with_Array() { delete Arr; }

void qeues_with_Array::pop(void) {
	Arr[rear] = -258;
	rear--;
}

void qeues_with_Array::push(int x) {
	if (rear >= SIZE) 
		return;
	Arr[rear] = x;
	if (rear + 1 != SIZE) 
		rear++;
}

void qeues_with_Array::log() {
	int FrontClone = front;
	while (FrontClone != rear) {
		printf("%d \n", Arr[FrontClone]);
		FrontClone++;
	}
	printf("%d \n", Arr[rear]);
}

int qeues_with_Array::Front(void) { return Arr[front]; }

int qeues_with_Array::Back(void) { return Arr[rear]; }

int qeues_with_Array::size(void) {
	int RES = 1;
	int FrontClone = front;
	while (FrontClone != rear) {
		RES++;
		FrontClone++;
	}
	return RES;
}

bool qeues_with_Array::Empty(void) {
	return rear == front;
}
