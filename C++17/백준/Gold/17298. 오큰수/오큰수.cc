#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> lst(n), result(n);
	for (int i = 0; i < n; i++) cin >> lst[i];
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= lst[i]) s.pop();
		if (s.empty()) result[i] = -1;
		else result[i] = s.top();
		s.push(lst[i]);
	};
	for (int i = 0; i < n; i++) cout << result[i] << " ";
}