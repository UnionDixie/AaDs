#include <iostream>

#include "PersStack.h"

int main(void) {

	PersStack stack;
	for (size_t i = 0; i < 5; i++)
	{
		stack.push(i, 0);
	}
	stack.print();
	std::cout << stack.topPop(4) << "\n";
	stack.print();
	

	return 0;
}
