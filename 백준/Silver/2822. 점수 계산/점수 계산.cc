#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;

int main() {
	map<int, int> dic;
	vector<int> lst;
	int a;
	for (int i = 1; i < 9; i++) {
		cin >> a;
		lst.push_back(a);
		dic[a] = i;
	}
	sort(lst.begin(), lst.end(), greater<int>());
	int sum = accumulate(lst.begin(), lst.begin() + 5, 0);
	vector<int> index;
	for (int i = 0; i < 5; i++) {
		index.push_back(dic[lst[i]]);
	}
	sort(index.begin(), index.end());
	cout << sum << "\n";
	for (int i = 0; i < 5; i++) {
		cout << index[i] << " ";
	}
}