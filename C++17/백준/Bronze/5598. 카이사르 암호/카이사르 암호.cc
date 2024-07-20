#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;
	cin >> s;
	int length = s.size();
	while (length--) {
		if (s[length] <= 67) s[length] += 23;
		else s[length] -= 3;
	}
	cout << s;
}