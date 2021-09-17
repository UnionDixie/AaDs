#include <iostream>
#include <vector>

using namespace std;


void insertSort(vector<int>& a) {
	for (size_t i = 0; i < a.size(); i++)
	{
		auto j = i;
		while (j > 0 && a[j] < a[j - 1])
		{
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

void insertSort2(vector<int>& a) {
	for (size_t i = 2; i < a.size(); i++)
	{
		auto key = a[i];
		auto j = i - 1;
		while (j > 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
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
	// Specify the engine and distribution.
	mt19937 mersenne_engine{ rnd_device() };  // Generates random integers
	uniform_int_distribution<int> dist{ 1, 1000 };

	auto gen = [&dist, &mersenne_engine]() {
		return dist(mersenne_engine);
	};

	vector<int> a(1e6);
	generate(begin(a), end(a), gen);
	auto b = a;

	auto start = std::chrono::steady_clock::now();
	insertSort(a);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	

	start = std::chrono::steady_clock::now();
	insertSort2(b);
	end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_seconds1 = end - start;
	std::cout << "elapsed time: " << elapsed_seconds1.count() << "s\n";
	
	std::cout << "ratio: " << 100.f - (elapsed_seconds1.count() * 100.f)/ elapsed_seconds.count() << "\n";



	return 0;
}