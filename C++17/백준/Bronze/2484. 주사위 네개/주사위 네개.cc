#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, t, sum;
	cin >> n;
	int max_val = 0;
	while (n--) {
		vector<int> lst(4);
		sum = 0;
		cin >> lst[0] >> lst[1] >> lst[2] >> lst[3];
		sort(lst.begin(), lst.end());
		if (lst[0] == lst[3]) sum += lst[3] * 5000 + 50000;
		else if (lst[0] == lst[2] || lst[1] == lst[3]) sum += lst[2] * 1000 + 10000;
		else if (lst[0] == lst[1] && lst[2] == lst[3]) sum += lst[3] * 500 + lst[1] * 500 + 2000;
		else if (lst[0] == lst[1] || lst[1] == lst[2] || lst[2] == lst[3]) {
			if (lst[0] == lst[1]) sum += lst[1] * 100 + 1000;
			if (lst[1] == lst[2]) sum += lst[2] * 100 + 1000;
			if (lst[2] == lst[3]) sum += lst[3] * 100 + 1000;
		}
		else sum += lst[3] * 100;
		max_val = max(max_val, sum);
	}
	cout << max_val;
}