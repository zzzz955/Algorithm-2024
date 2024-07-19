#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k;
	cin >> k;
	while (k--) {
		int p, m;
		cin >> p >> m;
		vector<int> lst(m);
		int cnt = 0;
		for (int i = 0; i < p; i++) {
			int a;
			cin >> a;
			if (count(lst.begin(), lst.end(), a)) cnt++;
			else lst.push_back(a);
		}
		cout << cnt << "\n";
	}
}