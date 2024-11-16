#include<iostream>
#include<queue>
using namespace std;

int n, k;
int lst[300000];
int v[21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		lst[i] = s.size();
	}

	long long ans = 0;
	queue<int> q;
	for (int i = 0; i <= k; ++i) {
		ans += v[lst[i]];
		v[lst[i]]++;
		q.push(lst[i]);
	}

	for (int i = k + 1; i < n; ++i) {
		v[q.front()]--;
		q.pop();
		ans += v[lst[i]];
		v[lst[i]]++;
		q.push(lst[i]);
	}

	cout << ans;
}