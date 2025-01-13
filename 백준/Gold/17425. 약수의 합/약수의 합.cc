#include<iostream>
#include<vector>
#define ll long long
using namespace std;

const int N = 1000001;
int t, n;
bool sosu[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<ll> F(N, 1);
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			F[j] += i;
		}
	}

	F[0] = 0;
	vector<ll> G(N);
	for (int i = 1; i < N; ++i) {
		G[i] = G[i - 1] + F[i];
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cout << G[n] << "\n";
	}
}