#include "PersStack.h"

int PersStack::topPop(int index)
{
	Query k = prestStack[prestStack[index].prevIndex];
	push(k.prevIndex, k.value);
	return prestStack[index].value;
}

void PersStack::push(int value, int index)
{
	if (size >= prestStack.size())
		prestStack.resize(size + 1);
	prestStack[size].value = value;
	prestStack[size].prevIndex = index;
	size++;
}

void PersStack::print()
{
	for (const auto& it: prestStack) {
		std::cout << it.value << " " << it.prevIndex << "\n";
	}
}

