#pragma once

#include <vector>
#include <iostream>

class PersStack
{
public:
	PersStack() = default;
	int topPop(int index);
	void push(int value, int index);
	void print();
	~PersStack() = default;
private:
	size_t size = 0;
	struct Query
	{
		int value = -1;
		int prevIndex = -1;
	};
	std::vector<Query> prestStack;
};

