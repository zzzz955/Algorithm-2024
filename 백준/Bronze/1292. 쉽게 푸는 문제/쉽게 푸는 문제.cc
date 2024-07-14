#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> lst = { 0 };
	int index = 1;
	int a, b;
	cin >> a >> b;
	while (lst.size() < 1001) {
		int cnt = index;
		while (cnt--) {
			lst.push_back(index);
		}
		index++;
	};
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += lst[i];
	}
	cout << sum;
}