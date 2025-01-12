#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;

ll N, P, Q;
unordered_map<ll, ll> v;

ll solve(ll n) {
	if (v[n]) return v[n];
	v[n] = solve(n / P) + solve(n / Q);
	return v[n];
}

int main() {
	cin >> N >> P >> Q;
	v[0] = 1;
	
	if (!N) cout << 1;
	else cout << solve(N / P) + solve(N / Q);
}