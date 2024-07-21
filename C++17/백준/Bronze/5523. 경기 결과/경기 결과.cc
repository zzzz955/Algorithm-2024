#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, a, b, aw = 0, bw = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (a == b) continue;
		if (a > b) aw++;
		if (a < b) bw++;
	}
	cout << aw << " " << bw;
}