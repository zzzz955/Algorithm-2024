#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 10, p1, p2;
	p1 = 0, p2 = 0;
	vector<int> a(10);
	vector<int> b(10);
	for (int i = 0; i < 20; i++) {
		if (i < 10) cin >> a[i];
		else cin >> b[i - 10];
	}
	while (n--) {
		if (a[n] == b[n]) continue;
		else if (a[n] > b[n]) p1++;
		else p2++;
	}
	if (p1 == p2) cout << "D\n";
	else if (p1 > p2) cout << "A\n";
	else cout << "B\n";
}