#include<iostream>
#include<vector>
using namespace std;

int n;
int nodes[100001];

int cnt[100001];
int idx[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nodes[i];
		idx[i] = 1e9;
	}

	vector<int> stack;
	for (int i = 1; i <= n; i++) {
		while (!stack.empty() && nodes[stack.back()] <= nodes[i]) {
			stack.pop_back();
		}
		if (!stack.empty()) {
			if (idx[i] - i > i - stack.back()) idx[i] = stack.back();
		}
		cnt[i] += stack.size();
		stack.push_back(i);
	}

	stack.clear();
	for (int i = n; i >= 1; i--) {
		while (!stack.empty() && nodes[stack.back()] <= nodes[i]) {
			stack.pop_back();
		}
		if (!stack.empty()) {
			if (abs(idx[i] - i) > abs(i - stack.back())) idx[i] = stack.back();
		}
		cnt[i] += stack.size();
		stack.push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		cout << cnt[i];
		if (cnt[i]) cout << " " << idx[i];
		cout << "\n";
	}
}
