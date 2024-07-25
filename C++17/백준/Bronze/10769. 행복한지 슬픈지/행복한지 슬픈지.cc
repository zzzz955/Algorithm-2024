#include <iostream>
#include <string>

using namespace std;

int main() {
	int cnt1 = 0, cnt2 = 0;
	string s;
	getline(cin, s);
	int c = 0;
	while (1) {
		int a = s.find(":-)", c);
		if (a == -1) break;
		cnt1++;
		c = a + 1;
	}
	c = 0;
	while (1) {
		int a = s.find(":-(", c);
		if (a == -1) break;
		cnt2++;
		c = a + 1;
	}
	if (!cnt1 && !cnt2) cout << "none";
	else if (cnt1 > cnt2) cout << "happy";
	else if (cnt1 < cnt2) cout << "sad";
	else cout << "unsure";
}
