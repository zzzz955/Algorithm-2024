#include <iostream>

using namespace std;

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	int area = w * w + h * h;
	while (n--) {
		int num;
		cin >> num;
		if (area >= num * num) cout << "DA\n";
		else cout << "NE\n";
	}
}