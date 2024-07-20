#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		string a = "";
		for (int j = n - i - 1; j > 0; j--) {
			a += " ";
		}
		a += "*";
		for (int j = 2 * i; j > 0; j--) {
			if (j == 1) a += "*";
			else a += " ";
		}
		cout << a << "\n";
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		cout << "*";
	}
}