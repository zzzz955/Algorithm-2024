#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> a(10);
	vector<int> b(10);
	for (int i = 0; i < 20; i++) {
		if (i < 10) cin >> a[i];
		else cin >> b[i - 10];
	}
	int ap = 0, bp = 0, last = 0;
	for (int i = 0; i < 10; i++) {
		if (a[i] == b[i]) {
			ap++;
			bp++;
		}
		else if (a[i] > b[i]) {
			ap += 3;
			last = 1;
		}
		else {
			bp += 3;
			last = 2;
		}
	}
	cout << ap << " " << bp << "\n";
	if (ap == bp) {
		if (last == 0) cout << "D";
		if (last == 1) cout << "A";
		if (last == 2) cout << "B";
	}
	else if (ap > bp) cout << "A";
	else cout << "B";
}
