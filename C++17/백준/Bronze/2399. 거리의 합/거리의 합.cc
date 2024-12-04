#include<iostream>
using namespace std;

int n;
int x[10000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];

	long long ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			ans += abs(x[i] - x[j]);
	cout << ans;
}