#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int n, ans;
int sosu[4000001];

int main() {
	cin >> n;
	for (int i = 2; i <= pow(n, (double)1/2); i++) {
		if (sosu[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			sosu[j] = 1;
		}
	}

	vector<int> sosus;
	for (int i = 2; i <= n; i++) {
		if (!sosu[i]) sosus.push_back(i);
	}

	int l = 0, r = 0, sum = 0, len = sosus.size();
	while (l <= r && r < len) {
		if (sum + sosus[r] < n) {
			sum += sosus[r];
			r++;
		}
		else if (sum + sosus[r] > n) {
			sum -= sosus[l];
			l++;
		}
		else {
			ans++;
			sum -= sosus[l];
			l++;
		}
	}
	cout << ans;
}