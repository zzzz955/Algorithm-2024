#include <iostream>

using namespace std;

int main() {
	int t, c, v, i, ans, piece;
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> c >> v;
		ans = c % v;
		piece = c / v;
		cout << "You get " << piece << " piece(s) and your dad gets " << ans << " piece(s).\n";
	}
}