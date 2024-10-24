#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int byeol[13] = { 0, 20, 19, 21, 20, 21, 22, 23, 23, 23, 23, 23, 22 };
int v[13];

struct MD {
	int m, d;
	bool operator<(const MD& other) const {
		if (m == other.m) return d < other.d;
		return m < other.m;
	}
};
vector<MD> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 7; i++) {
		int m, d; cin >> m >> d;
		if (d < byeol[m]) {
			m--;
			if (!m) m = 12;
		}
		v[m] = 1;
	}

	int n; cin >> n;
	while (n--) {
		int m, d; cin >> m >> d;
		if (d < byeol[m]) {
			int temp = m - 1;
			if (!temp) temp = 12;
			if (!v[temp]) ans.push_back({ m, d });
		}
		else if (!v[m]) ans.push_back({ m, d });
	}

	sort(ans.begin(), ans.end());

	if (ans.empty()) cout << "ALL FAILED";
	else {
		for (const MD& md : ans) cout << md.m << " " << md.d << "\n";
	}
}