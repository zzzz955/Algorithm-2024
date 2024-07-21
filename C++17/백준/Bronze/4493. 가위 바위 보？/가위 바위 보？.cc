#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, p1, p2;
	char a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		p1 = 0, p2 = 0;
		while (n--) {
			cin >> a >> b;
			if (a == b) continue;
			if (a == 'R' && b == 'P') p2++;
			if (a == 'S' && b == 'R') p2++;
			if (a == 'P' && b == 'S') p2++;
			if (a == 'P' && b == 'R') p1++;
			if (a == 'R' && b == 'S') p1++;
			if (a == 'S' && b == 'P') p1++;
		}
		if (p1 == p2) cout << "TIE\n";
		else if (p1 > p2) cout << "Player 1\n";
		else cout << "Player 2\n";
	}
}