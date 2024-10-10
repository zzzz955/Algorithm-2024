#include<iostream>
#include<queue>
#include<algorithm>
#define pii pair<int, int>

using namespace std;

int n, d, ans;
pii nums[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;
		if (s > e) swap(s, e);
		nums[i] = { e, s };
	}

	sort(nums, nums + n);
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> d;
	for (int i = 0; i < n; i++) {
		pii cur = nums[i];
		int s = cur.second, e = cur.first;

		if (e - s <= d) pq.push(s);
		else continue;

		while (!pq.empty() && pq.top() < e - d) pq.pop();

		ans = max(ans, (int)pq.size());
	}
	cout << ans;
}