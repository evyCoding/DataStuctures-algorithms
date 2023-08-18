#include "linked_list.h"

int main()
{
	auto* list = new DoubleLinkedList;
	std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 9};
	list->create(vec);
	list->Display();
} 
