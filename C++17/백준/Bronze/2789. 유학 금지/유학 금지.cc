#include <iostream>
#include <string>

using namespace std;

int main() {
	string ban = "CAMBRIDGE";
	string a, ans = "";
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (ban.find(a[i]) == ban.npos) ans += a[i];
	}
	cout << ans;
}