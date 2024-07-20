#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	if (n % 2) {
		int length = a.size();
		while (length--) {
			if (a[length] == '0') a[length] = '1';
			else a[length] = '0';
		}
	}
	if (a == b) cout << "Deletion succeeded";
	else cout << "Deletion failed";
}