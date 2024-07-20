#include <iostream>

using namespace std;

int main() {
	int n, a;
	cin >> n;
	while (1) {
		cin >> a;
		if (a == 0) break;
		if (a % n) cout << a << " is NOT a multiple of " << n << ".\n";
		else cout << a << " is a multiple of " << n << ".\n";
	}
}