#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int abcd[4000][4];
vector<int> ab;
vector<int> cd;
ll ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> abcd[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(abcd[i][0] + abcd[j][1]);
			cd.push_back(abcd[i][2] + abcd[j][3]);
		}
	}

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	ll p1 = 0, p2 = n * n - 1;
	while (p1 < n * n && 0 <= p2) {
		int sum = ab[p1] + cd[p2];
		if (sum > 0) p2--;
		else if (sum < 0) p1++;
		else {
			auto it1 = upper_bound(ab.begin(), ab.end(), ab[p1]);
			auto it2 = lower_bound(cd.begin(), cd.end(), cd[p2]);
			ll cnt1 = it1 - ab.begin();
			ll cnt2 = it2 - cd.begin();
			//long long cnt1 = 1, cnt2 = 1;
			//while (p1 + cnt1 < n * n && ab[p1 + cnt1] == ab[p1]) cnt1++;
			//while (p2 - cnt2 >= 0 && cd[p2 - cnt2] == cd[p2]) cnt2++;
			ans += (cnt1 - p1) * (p2 - cnt2 + 1);
			p1 = cnt1;
			p2 = cnt2 - 1;
		}
	}
	cout << ans;
}