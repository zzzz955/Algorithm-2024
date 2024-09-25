#include<iostream>
#include<set>

using namespace std;

int n, m;

struct Prob {
	int l, g;
};
Prob probs[100001];

set<pair<int, int>> rec1[100001];
set<pair<int, int>> rec2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int p, l, g; cin >> p >> l >> g;
		rec1[g].insert({ l, p });
		rec2.insert({ l, p });
		probs[p] = { l, g };
	}
	cin >> m;
	while (m--) {
		string order; cin >> order;
		if (order == "add") {
			int p, l, g; cin >> p >> l >> g;
			probs[p] = { l, g };
			rec1[g].insert({ l, p });
			rec2.insert({ l, p });
		}
		else if (order == "solved") {
			int p; cin >> p;
			Prob& prob = probs[p];
			int l = prob.l, g = prob.g;
			rec1[g].erase({ l, p });
			rec2.erase({ l, p });
		}
		else if (order == "recommend") {
			int g, x; cin >> g >> x;
			if (x == 1) {
				auto it = rec1[g].rbegin();
				cout << (*it).second << "\n";
			}
			else {
				auto it = rec1[g].begin();
				cout << (*it).second << "\n";
			}
		}
		else if (order == "recommend2") {
			int x; cin >> x;
			if (x == 1) {
				auto it = rec2.rbegin();
				cout << (*it).second << "\n";
			}
			else {
				auto it = rec2.begin();
				cout << (*it).second << "\n";
			}
		}
		else {
			int x, L; cin >> x >> L;
			if (x == 1) {
				auto it = rec2.lower_bound({ L, 0 });
				if (it == rec2.end()) cout << -1 << "\n";
				else cout << (*it).second << "\n";
			}
			else {
				auto it = rec2.lower_bound({ L, 0 });
				if (it == rec2.begin()) cout << -1 << "\n";
				else cout << (*--it).second << "\n";
			}
		}
	}
}