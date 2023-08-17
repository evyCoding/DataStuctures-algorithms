#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Node
{
public:
	int Data;
	Node* next;

	explicit Node() : Data(0), next(nullptr) {};
	~Node() { delete next; };
};

class linkedList
{
public:
	 Node* Head = new Node;
	 Node* Tail = Head;
public:
	void append(int x);

	void insertByTail(int x);

	void insertIfSorted(int x);

	void deleteTail(void);

	void deleteHead(void);

	void Delete(int pos);

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
