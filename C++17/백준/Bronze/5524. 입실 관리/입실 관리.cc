#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n, length;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		length = s.size();
		while (length--) {
			s[length] = tolower(s[length]);
		}
		cout << s << "\n";
	}
}