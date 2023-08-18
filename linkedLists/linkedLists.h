#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

struct Node
{
	int Data;
	Node* next;
	//todo : consturctor & destructor
	explicit Node(void) : Data(0), next(nullptr) {};
	~Node() { delete next; };
};

class linkedList
{
public:
	 Node* Head = new Node;
	 Node* Tail = Head;
public:
	void create(std::vector<int> vex);

	void append(int x);

	void insert(int index, int value); // index base 0

	void appendByTail(int x);

	void appendifSorted(int x);

	void deleteTail(void);

	void deleteHead(void);

	void Delete(int pos); // index base 0

	void DeleteByValue(int val);

	void Display(void);

	void Display_recurcive(Node* sel);

	bool isEmpty(void);

	bool isSorted(void);

	bool ISLOPPED(void);

	int linear_search(int element);

	int counting_nodes(void);

	int sum(void);

	int max(void);

	int min(void);

	void remove_duplicates_if_sorted(void);

	void reverse_one(void);

	void reverse_two(void);

	void merge(linkedList * list);

};

class CircularLinkedList
{
private:
	Node* Head = new Node;
public:
	CircularLinkedList(void);
	
	void create(std::vector<int> vex);

	void Display(void);

	void append(int value);

	void Delete(int position); // index base 0

	void DeleteHead();

	int CountingNodes(void);
};

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
private:
	DoubleNode* Head = new DoubleNode;
	DoubleNode* Tail = Head;
public:
	void create(std::vector<int> vex);

	void Display(void);

	void revDisplay(void);

	void insert(int index, int value); // -1 index == switch head
	
	void append(int x);
	
	void Delete(int position);

	void DeleteHead(void);
};
