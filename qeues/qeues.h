#include <iostream>

#pragma once

class qeues_with_Array
{
private:
	int* Arr{};
	size_t SIZE{};
	int front = 0;
	int rear = 0;
public:
	// constructor && destructor
	qeues_with_Array();
	~qeues_with_Array();
	// function :
	void pop(void);
	void push(int x);
	void log();
	int Front(void);
	int Back(void);
	int size(void);
	bool Empty(void);
};

