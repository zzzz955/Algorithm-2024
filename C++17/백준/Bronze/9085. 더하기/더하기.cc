#include <iostream>

using namespace std;

int main() {
	int t, n, num, sum, i, j;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n;
		sum = 0;
		for (j = 0; j < n; j++) {
			cin >> num;
			if (num <= 10) sum += num;
		}
		cout << sum << "\n";
	}
}