#include <iostream>
#include <vector>

using namespace std;


vector<int> merge(const vector<int>& a, const vector<int>& b) {
	auto n = a.size();
	auto m = b.size();
	auto z = m + n;
	vector<int> c(z);

	int i = 0, j = 0, k = 0;

	while (i < n || j < m)
	{
		if (j == m || i < n && a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
	return c;
}

vector<int> mergeSort(vector<int>& a) {
	auto n = a.size();
	if (n <= 1)
		return a;
	vector<int> al, ar;
	for (size_t i = 0; i <= n/2 - 1; i++)
		al.push_back(a[i]);
	for (size_t i = n/2; i < n; i++)
		ar.push_back(a[i]);
	al = mergeSort(al);
	ar = mergeSort(ar);
	return merge(al, ar);	
}


template<typename T>
void print(T& a) {
	for (auto it : a) {
		cout << it << " ";
	}
	cout << "\n";
}

#include <random>
#include <chrono>

int main(void) {

	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };
	uniform_int_distribution<int> dist{ 1, 1000 };

	auto gen = [&dist, &mersenne_engine]() {
		return dist(mersenne_engine);
	};

	vector<int> a(1e6);
	generate(begin(a), end(a), gen);
	auto b = a;
	//print(a);
	auto start = std::chrono::steady_clock::now();
	a = mergeSort(a);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	//print(a);




	return 0;
}