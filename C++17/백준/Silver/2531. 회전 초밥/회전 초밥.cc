#include<iostream>
#include<deque>
using namespace std;

int n, d, k, c, ans;
int v[30000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	deque<int> deq;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		deq.push_back(a);
	};

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (!v[deq[i]]) cnt++;
		v[deq[i]]++;
	}
	ans = cnt;

	while (n--) {
		if (v[deq[0]] == 1) cnt--;
		v[deq[0]]--;
		deq.push_back(deq.front());
		deq.pop_front();
		if (!v[deq[k - 1]]) cnt++;
		v[deq[k - 1]]++;
		if (v[c]) ans = max(ans, cnt);
		else ans = max(ans, cnt + 1);
	}
	cout << ans;
}