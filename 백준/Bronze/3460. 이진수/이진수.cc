#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t, n, i, j, c;
	cin >> t;
	vector<int> lst = { 1 };
	for (i = 0; i < 20; i++) {
		lst.push_back(lst[i] * 2);
	}
	reverse(lst.begin(), lst.end());
	for (c = 0; c < t; c++) {
		string a = "";
		for (i = 0; i < t; i++) {
			cin >> n;
			for (j = 0; j <= 20; j++) {
				if (n >= lst[j]) {
					n -= lst[j];
					a += "1";
				}
				else a += "0";
			}
			reverse(a.begin(), a.end());
			for (i = 0; i <= 20; i++) {
				if (a[i] == '1') cout << i << " ";
			}
		}
	}
}