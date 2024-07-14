#include <iostream>

using namespace std;

int main() {
	int a, b, i;
	cin >> a;
	int cnt = 0;
	for (i = 0; i < 5; i++) {
		cin >> b;
		if (a == b) cnt++;
	}
	cout << cnt;
}