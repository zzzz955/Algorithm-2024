#include <iostream>

using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		if (i % 2) {
			for (j = 0; j < n; j++) {
				cout << " *";
			}
		}
		else {
			for (j = 0; j < n; j++) {
				cout << "* ";
			}
		}

		cout << "\n";
	}
}