#include "linked_list.h"


void linkedList::append(int x) {
	auto* p = new Node;
	p->Data = x;
	p->next = nullptr;

	Node* q = Head;
	while (q->next)
		q = q->next;
	q->next = p;
}

void linkedList::insertByTail(int x) {
	Node* n = new Node;
	n->Data = x;
	n->next = nullptr;
	Tail->next = n;
	Tail = n;
}

void linkedList::insertIfSorted(int x) {
	Node* n = new Node;
	Node* keep = Head;
	Node* keep_pre = nullptr;
	n->Data = x;
	n->next = nullptr;
	while (keep->Data < x) {
		keep_pre = keep;
		keep = keep->next;
	}
	if (keep == Head) {
		n->next = Head;
		Head = n;
	}
	else if (keep == Tail)
		this->insertByTail(x);
	else {
		keep_pre->next = n;
		n->next = keep;
	}
}	


void linkedList::deleteHead(void) {
	auto* KeepTrack = Head->next;
	Head = KeepTrack;
}

void linkedList::deleteTail(void) {
	auto* n = Head;
	while (n->next->next)
		n = n->next;
	n->next = nullptr;
	Tail = n;
}

void linkedList::Delete(int pos)  {
	if (pos <= 0 || !Head || !Head->next || this->counting_nodes() - 1 < pos)
		return;
	int count(1);
	Node* pre = nullptr;
	auto* curr = Head;
	for (count; count < pos + 1 && curr; count++) {
		pre = curr;
		curr = curr->next;
	}
	if (curr == Tail)
		pre->next = nullptr;
	else
		pre->next = curr->next;
}

void linkedList::DeleteByValue(int val) {
	if (!Head || !Head->next)
		return;
	Node* pre = Head;
	auto* curr = Head->next;
	while(curr && curr->Data != val) {
		pre = curr;
		curr = curr->next;
	}
	if (pre == Tail && pre->Data == val)
		pre->next = nullptr;
	if (pre == Tail && pre->Data != val)
		std::cerr << "values not found !" << std::endl;
	else
		pre->next = curr->next;
}

void linkedList::Display(void) {
	auto* p = Head;
	while (p->next)
	{
		std::cout << p->Data << ' ';
		p = p->next;
	}
	std::cout << p->Data;
}

void linkedList::Display_recurcive(Node *sel)
{
	static bool one = true;
	if (one) {
		sel = Head;
		one = false;
	}
	if (!sel->next) {
		std::cout << sel->Data << ' ';
		return;
	}
	else {
		Display_recurcive(sel->next);
		std::cout << sel->Data << ' ';
	}
}

bool linkedList::isEmpty(void) { return !Head->next; }

bool linkedList::isSorted(void) {
	Node* bef = Head;
	Node* aff = Head->next;
	while (aff->next) {
		if (bef->Data > aff->Data)
			return false;
		bef = bef->next;
		aff = aff->next;
	}
	return bef->Data < aff->Data;
}

bool linkedList::ISLOPPED(void) {
	auto* p = Head;
	auto* q = Head;
	while(p) {
		q = q->next;
		for(int i = 0; i < 2; i++) {
			if (p)
				p = p->next;
			else
				return false;
		} 
		if (p == q) 
			return true;
	}
	return false;
}

int linkedList::linear_search(int element) {
	auto ptr = Head;
	int count(0);
	while (ptr->next != nullptr) {
		if (ptr->Data == element)
			return count;
		else {
			count++;
			ptr = ptr->next;
		}
	}
	return -1;
}

int linkedList::counting_nodes(void) {
	Node *n = Head;
	int c(1);
	while (n->next != nullptr) {
		c++;
		n = n->next;
	}
	return c;
}

int linkedList::sum(void) {
	Node* n = Head;
	int sum(0);
	while (n->next != nullptr) {
		sum += n->Data;
		n = n->next;
	}
	sum += n->Data;
	return sum;
}

int linkedList::max(void) {
	Node* m = Head;
	int max_val = m->Data;
	while (m->next != nullptr) {
		if (max_val < m->Data) 
			max_val = m->Data;
		m = m->next;
	}
	if (max_val < m->Data)
		max_val = m->Data;
	return max_val;
}

int linkedList::min(void) {
	Node* m = Head;
	int min_val = m->Data;
	while (m->next != nullptr) {
		if (min_val > m->Data)
			min_val = m->Data;
		m = m->next;
	}
	if (min_val > m->Data)
		min_val = m->Data;
	return min_val;
}

void linkedList::remove_duplicates_if_sorted(void) {
	Node* p = Head;
	Node* q = Head->next;
	while (q != nullptr) {
		if (p->Data != q->Data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			q = p->next;
		}
	}
}

void linkedList::reverse_one(void) {
	std::vector<int> vec;
	Node* ptr = Head;
	while (ptr)
	{
		vec.push_back(ptr->Data);
		ptr = ptr->next;
	}
	std::reverse(vec.begin(), vec.end());
	ptr = Head;
	int counter(0);
	while (ptr && counter < counting_nodes())
	{
		ptr->Data = vec[counter];
		counter++;
		ptr = ptr->next;
	}
}

void linkedList::reverse_two(void) {
	Node* r = nullptr;
	Node* q = nullptr;
	Node* p = Head;
	while(p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	Head = Tail;
}

void linkedList::merge(linkedList* list) { Tail->next = list->Head; }



