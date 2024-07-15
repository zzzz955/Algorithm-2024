#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> lst;
		for (int j = 0; j < 5; j++) {
			int num;
			cin >> num;
			lst.push_back(num);
		}
		sort(lst.begin(), lst.end());
		lst.erase(lst.begin(), lst.begin() + 1);
		lst.pop_back();
		if (lst[0] + 3 < lst[2]) {
			cout << "KIN\n";
		}
		else {
			int sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += lst[j];
			}
			cout << sum << "\n";
		}
	}
}