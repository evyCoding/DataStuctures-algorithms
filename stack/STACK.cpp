#include "STACK.h"

St::St()
{
	A = new DoubleLinkedList;
	/*std::cout << "enter the size of the stack ";
	std::cout << '\n' << "->Stack ";
	std::cin >> SIZE;
	A = new int[SIZE];
	top = -1;*/ //todo : only for implementaion with Arrays
}

int St::countingNodes() {
	auto* n = Head->next;
	int k(0);
	while (n) {
		k++;
		n = n->next;
	}
	return k;
}

void St::push(int x)
{
	DoubleNode* n = new DoubleNode;
	n->Data = x;
	n->next = nullptr;
	n->prev = nullptr;
	DoubleNode* keepTrack = A->Head;
	while (keepTrack->next)
		keepTrack = keepTrack->next;
	keepTrack->next = n;
	n->prev = keepTrack;
	A->top = n;
}

void St::pop() {
	A->top = A->top->prev;
	(A->top->next)->prev = nullptr;
	A->top->next = nullptr;
}

void St::Display(void) {
	auto* stx = new St;
	stx = this;

	while (A->top != A->Head) {
		std::cout << stx->Top() << ' ';
		stx->pop();
	}
}

int St::Top()
{
	if (A->top == A->Head)
		return 0;
	else {
		return A->top->Data;
	}
}

int St::per(int pos)
{
	int Nnodes = countingNodes();
	if (A->top == A->Head)
		return 0;
	else {
		int topCount(0);
		DoubleNode* n = A->top;
		while (n) {
			if (topCount == pos)
				return n->Data;
			else {
				n = n->prev;
				topCount++;
			}
		}
		return -258;
	}
}

/*bool St::isFULL() // linked lists has can aloccate to many nodes as long that the Heap is free
{
	if (A->top == SIZE - 1)
		return true;
	else
		return false;
}*/

bool St::isEMPTY()
{
	if (A->top == A->Head)
		return true;
	else
		return false;
}
