#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int a = (int)s[0] - 48, b = (int)s[2] - 48;
		cout << a + b << "\n";
	}
}