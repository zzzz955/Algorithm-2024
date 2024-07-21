#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, temp, abc = "abcdefghijklmnopqrstuvwxyz";
	while (1) {
		getline(cin, s);
		if (s == "*") break;
		temp = "";
		int length = s.size(), flag = 1;
		while (length--) {
			if (s[length] != ' ') {
				temp += s[length];
			}
		}
		length = abc.size();
		while (length--) {
			if (temp.find(abc[length]) == temp.npos) {
				flag = 0;
				break;
			}
		}
		if (flag) cout << "Y\n";
		else cout << "N\n";
	}
}