#include "qeues.h"
#include <vector>
#include <iostream>



int main() {
	auto* myQeue = new qeues_with_Array;
	myQeue->push(1);
	myQeue->push(2);
	myQeue->push(3);
	myQeue->push(4);
	myQeue->log();
}
