#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int, int>
using namespace std;

int n, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	while (n--) {
		int a, b; cin >> a >> b;
		pq.push({ a, b });
	}

	vector<int> lis;
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		auto it = lower_bound(lis.begin(), lis.end(), cur.second);
		if (it == lis.end()) lis.push_back(cur.second);
		else {
			*it = cur.second;
			ans++;
		}
	}
	cout << ans;
}