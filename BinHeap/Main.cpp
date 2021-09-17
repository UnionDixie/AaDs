#include <iostream>
#include <vector>

using namespace std;


void siftUp(vector<int>& a) {
	auto i = a.size() - 1;
	while (i > 0 && a[i] < a[(i - 1) / 2])
	{
		swap(a[i], a[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void insert(vector<int>& heap, int x) {
	heap.push_back(x);
	siftUp(heap);
}

void siftDown(vector<int>& a) {
	auto i = 0u;
	while (true)
	{
		auto j = i;
		if (2 * i + 1 < a.size() && a[2 * i + 1] < a[j]) {
			j = 2 * i + 1;
		}
		if (2 * i + 2 < a.size() && a[2 * i + 2] < a[j]) {
			j = 2 * i + 2;
		}
		if (j == i) {
			break;
		}
		swap(a[i], a[j]);
		i = j;
	}
}

int remove_min(vector<int>& a) {
	auto res = a[0];
	a[0] = a.back();
	a.pop_back();
	siftDown(a);
	return res;
}

void StartHeap() {
	vector<int> heap{ 3,7,5,8,11,10,13,14,27,18,38 };
	insert(heap, 4);
	auto x = remove_min(heap);
	int y = 2;
}

void heapSort(vector<int>& a) {
	vector<int> b;
	for (size_t i = 0; i < a.size(); i++)
	{
		insert(b, a[i]);
	}
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = remove_min(b);
	}
	a = b;
}


int main(void) {
	//StartHeap();
	vector<int> a = { 44, 23, 254, 76, 9, 8, 4, 1, 3, 5 };
	heapSort(a);//memory O(n)

	return 0;
}