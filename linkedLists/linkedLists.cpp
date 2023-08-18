#include "linked_list.h"

//todo -> linkedLists :

void linkedList::create(std::vector<int> vex) {
	Head->Data = vex[0];
	for (int i = 1; i < vex.size(); i++)
		appendByTail(vex[i]);
}

void linkedList::append(int x) {
	auto* p = new Node;
	p->Data = x;
	p->next = nullptr;

	Node* q = Head;
	while (q->next)
		q = q->next;
	q->next = p;
}

void linkedList::insert(int index, int value) {
	int k = 1;
	Node* n = new Node;
	n->Data = value;
	n->next = nullptr;
	Node* p = Head;
	Node* q = Head->next;
	while (k != index) {
		p = p->next;
		q = q->next;
		k++;
	}
	p->next = n;
	n->next = q;
}

void linkedList::appendByTail(int x) {
	Node* n = new Node;
	n->Data = x;
	n->next = nullptr;
	Tail->next = n;
	Tail = n;
}

void linkedList::appendifSorted(int x) {
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
		this->appendByTail(x);
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
	while (p)
	{
		std::cout << p->Data << ' ';
		p = p->next;
	}
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

// todo->circularLinkedLists :

CircularLinkedList::CircularLinkedList(void) {
	Head->next = Head;
	Head->Data = 0;
}

void CircularLinkedList::create(std::vector<int> vex) {
	for (int i = 0; i < vex.size(); i++)
		append(vex[i]);
}

void CircularLinkedList::Display(void) {
	auto* keepTrack = Head->next;
	while (keepTrack != Head) {
		std::cout << keepTrack->Data << std::endl;
		keepTrack = keepTrack->next;
	}
}

void CircularLinkedList::append(int value) {
	auto* n = new Node;
	auto* keepTrack = Head;
	n->Data = value;
	n->next = Head;
	while (keepTrack->next != Head)
		keepTrack = keepTrack->next;
	keepTrack->next = n;
}

int CircularLinkedList::CountingNodes(void) {
	int k(0);
	auto* keepTrack = Head->next;
	while (keepTrack != Head) {
		keepTrack = keepTrack->next;
		k++;
	}
	return k;
}

void CircularLinkedList::Delete(int pos) {
	if (pos < 0 || Head == Head->next || this->CountingNodes() - 1 < pos)
		return;
	if (pos == 0) {
		if ((Head->next)->next == Head)
			Head->next == Head;
		else
			Head->next = (Head->next)->next;
	}
	int count(0);
	Node* pre = nullptr;
	auto* curr = Head->next;
	for (count; count < pos && curr != Head; count++) {
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
}

void CircularLinkedList::DeleteHead() {
	Head = Head->next;
}

//todo : DoubleLinkedLists

void DoubleLinkedList::create(std::vector<int> vex) {
	for (int i = 0; i < vex.size(); i++)
		this->append(vex[i]);
}

void DoubleLinkedList::Display(void) {
	auto* p = Head;
	while (p)
	{
		std::cout << p->Data << ' ';
		p = p->next;
	}
}

void DoubleLinkedList::revDisplay(void) {
	DoubleNode* keepTrack = Tail;
	do {
		std::cout << keepTrack->Data << " ";
		keepTrack = keepTrack->prev;
	} while (keepTrack);
}

void DoubleLinkedList::insert(int index, int value) {
	DoubleNode* n = new DoubleNode;
	n->Data = value;
	n->next = nullptr;
	n->prev = nullptr;
	DoubleNode* p = nullptr;
	DoubleNode* q = Head;
	int k(-1);
	while (k != index) {
		p = q;
		q = q->next;
		k++;
	}
	if (!p && q) {
		n->next = Head;
		Head = n;
	}
	else {
		p->next = n;
		n->prev = p;
		n->next = q;
	}
}

void DoubleLinkedList::append(int x) {
	auto* n = new DoubleNode;
	n->next = nullptr;
	n->prev = nullptr;
	n->Data = x;
	auto* p = Head;
	while (p->next)
		p = p->next;
	p->next = n;
	n->prev = p;
	Tail = n;
}

void DoubleLinkedList::Delete(int position) {
	int k(0);
	DoubleNode* p = Head;
	DoubleNode* q = Head->next;
	while (k != position) {
		p = q;
		q = q->next;
		k++;
	}
	p->next = q->next;
}

void DoubleLinkedList::DeleteHead(void) { Head = Head->next; }
