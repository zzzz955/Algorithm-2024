#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << ".\n";
	}
}