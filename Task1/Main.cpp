#include <iostream>
#include <vector>


using namespace std;

namespace solve1 {
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

	void task1() {
		vector<int> a{ 1,2,3,4 }, b{ 8,9,10,11 };
		auto c = merge(a, b);
		bool ok = false;
		for (size_t i = 0; i < c.size() - 1; i++)
		{
			if (c[i] == c[i + 1]) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			cout << "ok\n";
		}
		else {
			cout << "no\n";
		}

	}
}

int main() {

	//solve1::task1();
	



	return 0;
}


