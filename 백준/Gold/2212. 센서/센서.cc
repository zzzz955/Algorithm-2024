#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, k, ans;
int lst[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> lst[i];
	sort(lst, lst + n);

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i < n; ++i) pq.push(lst[i] - lst[i - 1]);

	while (pq.size() > k - 1) pq.pop();
	while (!pq.empty()) {
		ans += pq.top(); pq.pop();
	}
	cout << lst[n - 1] - lst[0] - ans;
}