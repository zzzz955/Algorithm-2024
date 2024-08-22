#include<iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b >= c) cout << -1;
	else {
		int d = c - b;
		cout << a / d + 1;
	}
}