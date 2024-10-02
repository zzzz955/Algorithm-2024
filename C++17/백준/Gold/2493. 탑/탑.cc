#include<iostream>
#include<stack>

using namespace std;
int n;
int lst[500001], ans[500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> lst[i];
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		while (!s.empty() && lst[s.top()] <= lst[i]) s.pop();
		if (s.empty()) ans[i] = 0;
		else ans[i] = s.top();
		s.push(i);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}