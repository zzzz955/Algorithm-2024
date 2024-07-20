#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int t, a, b, temp1, temp2;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		temp1 = max(a, b), temp2 = max(a, b);
		while (temp1) {
			if (temp1 % a == 0 && temp1 % b == 0) break;
			else temp1++;
		}
		while (temp2) {
			if (a % temp2 == 0 && b % temp2 == 0) break;
			else temp2--;
		}
		cout << temp1 << " " << temp2 << "\n";
	}
}