#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		int n;
		cin >> n;
		vector<int> lst(n);
		int max_val = -1;
		int min_val = 101;
		int large = -1;
		for (int i = 0; i < n; i++) {
			cin >> lst[i];
			max_val = max(max_val, lst[i]);
			min_val = min(min_val, lst[i]);
		}
		sort(lst.begin(), lst.end());
		for (int i = 0; i < n - 1; i++) {
			large = max(large, lst[i + 1] - lst[i]);
		}
		cout << "Class " << c << "\n";
		cout << "Max " << max_val << ", Min " << min_val << ", Largest gap " << large << "\n";
	}
}