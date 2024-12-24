#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;

int t, n, m, A, B, sumA[1000], sumB[1000];
unordered_map<int, ll> dicA, dicB;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	cin >> n;
	ll prefix = 0;
	for (int i = 0; i < n; ++i) {
		cin >> A;
		prefix += A;
		sumA[i] = prefix;
		dicA[prefix]++;
		for (int j = 0; j < i; ++j) dicA[sumA[i] - sumA[j]]++;
	}

	cin >> m;
	prefix = 0;
	for (int i = 0; i < m; ++i) {
		cin >> B;
		prefix += B;
		sumB[i] = prefix;
		dicB[prefix]++;
		for (int j = 0; j < i; ++j) dicB[sumB[i] - sumB[j]]++;
	}

	ll ans = 0;
	for (const auto& d : dicA) {
		int key = t - d.first;
		if (dicB[key]) ans += dicB[key] * d.second;
	}
	cout << ans;
}