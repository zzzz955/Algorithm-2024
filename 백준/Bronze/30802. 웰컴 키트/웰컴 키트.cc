#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n, a, t, p, i, j;
	vector<int> shirts;
	cin >> n;
	for (i = 0; i < 6; i++) {
		cin >> a;
		shirts.push_back(a);
	}
	cin >> t >> p;
	int cnt = 0;
	for (i = 0; i < 6; i++) {
		cnt += ceil((double)shirts[i] / t);
	}
	cout << cnt << "\n";
	cout << n / p << " " << n % p;
}