#include<iostream>
#include<set>

using namespace std;

int tc, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> k;
		multiset<int> dic;
		while (k--) {
			char order; cin >> order;
			int n; cin >> n;
			if (order == 'I') dic.insert(n);
			else {
				if (dic.empty()) continue;
				if (n == 1) dic.erase(--dic.end());
				else dic.erase(dic.begin());
			}
		}
		if (dic.empty()) cout << "EMPTY\n";
		else cout << *--dic.end()  << " " << *dic.begin() << "\n";
	}
}