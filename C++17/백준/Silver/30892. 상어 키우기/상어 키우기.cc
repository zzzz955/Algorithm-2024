#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
long long t;

int main() {
	cin >> n >> k >> t;
	int cnt = 0;
	vector<int> lst(n);
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	sort(lst.begin(), lst.end());
	priority_queue<int> lower;
	priority_queue<int, vector<int>, greater<int>> bigger;

	while (!lst.empty()) {
		if (lst.back() >= t) {
			bigger.push(lst.back());
			lst.pop_back();
		}
		else {
			lower.push(lst.back());
			lst.pop_back();
		}
	}

	while (cnt < k) {
		while (!bigger.empty() && bigger.top() < t) {
			lower.push(bigger.top());
			bigger.pop();
		}
		if (lower.empty()) break;
		t += lower.top();
		lower.pop();
		cnt++;
	}
	cout << t;
}