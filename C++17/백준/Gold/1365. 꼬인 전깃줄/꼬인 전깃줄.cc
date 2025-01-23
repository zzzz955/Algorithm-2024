#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> lis;
	cin >> n;
	while (n--) {
		int num; cin >> num;
		auto it = lower_bound(lis.begin(), lis.end(), num);
		if (it == lis.end()) lis.push_back(num);
		else {
			ans++;
			*it = num;
		}
	}
	cout << ans;
}