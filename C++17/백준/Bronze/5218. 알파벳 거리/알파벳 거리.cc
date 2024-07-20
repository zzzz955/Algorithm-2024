#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		string ans = "Distances:";
		for (int i = 0; i < a.size(); i++) {
			if (b[i] >= a[i]) ans += " " + to_string(b[i] - a[i]);
			else ans += " " + to_string(b[i] + 26 - a[i]);
		}
		cout << ans << "\n";
	}
}