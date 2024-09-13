#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> ans;
	while (n--) {
		int port; cin >> port;
		auto it = lower_bound(ans.begin(), ans.end(), port);
		if (it == ans.end()) ans.push_back(port);
		else *it = port;
	}
	cout << ans.size();
}