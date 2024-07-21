#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	int up = 1, down = 24;
	for (int i = n; i > n - 4; i--) {
		up *= i;
	}
	cout << up / down;
}