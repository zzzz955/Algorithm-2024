#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sum = 0;
		int min_val = 101;
		for (int i = 0; i < 7; i++) {
			int a;
			cin >> a;
			if (a % 2 == 0) {
				sum += a;
				min_val = min(min_val, a);
			}
		}
		cout << sum << " " << min_val << "\n";
	}
}