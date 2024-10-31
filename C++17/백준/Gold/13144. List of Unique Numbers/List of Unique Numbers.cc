#include<iostream>
using namespace std;

int n;
int nodes[100000];
int v[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> nodes[i];
	int l = 0, r = 0;

	long long ans = 0;
	while (r < n) {
		if (!v[nodes[r]]) {
			ans += r - l + 1;
			v[nodes[r++]]++;
		}
		else {
			while (v[nodes[r]]) v[nodes[l++]]--;
		}
	}
	cout << ans;
}