#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	string s;
	int n;
	int cnt = 0;
	cin >> s >> n;
	int length = s.size();
	while (n--) {
		int index = 0;
		string str;
		cin >> str;
		int a = str.find(s[0]);
		if (a == -1)continue;
		str = str.substr(a, str.size()) + str.substr(0, a);
		for (int i = 0; i < 10; i++) {
			if (str[i] == s[index]) index++;
			if (index == length) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}
