#pragma once
#include <iostream>
//**********************************************************

struct DoubleNode
{
	int Data;
	DoubleNode* next;
	DoubleNode* prev;
	//todo : constructor & destructor
	explicit DoubleNode() : Data(0), next(nullptr), prev(nullptr) {}
	~DoubleNode() {
		delete next;
		delete prev;
	}
};

class DoubleLinkedList
{
public:
	DoubleNode* Head = new DoubleNode;
	DoubleNode* top = Head;
};

class St : public DoubleLinkedList
{
private:
	DoubleLinkedList* A;
	//int top; todo : only for implementaion with Arrays
	//int SIZE; todo : only for implementaion with Arrays
public:
	St();
	int Top();
	int per(int pos);
	int countingNodes();
	void push(int x);
	void pop(void);
	void Display(void);
	//bool isFULL();  : only for implementaion with Arrays
	bool isEMPTY();
};
