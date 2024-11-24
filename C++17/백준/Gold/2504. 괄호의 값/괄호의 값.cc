#include<iostream>
#include<vector>
using namespace std;

string s;
vector<char> stack;

int main() {
	cin >> s;
	int ans = 0, temp = 1;
	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
		case '(':
			temp *= 2;
			stack.push_back(s[i]);
			break;
		case '[':
			temp *= 3;
			stack.push_back(s[i]);
			break;
		case ')':
			if (stack.empty() || stack.back() != '(') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '(') ans += temp;
			temp /= 2;
			stack.pop_back();
			break;
		case ']':
			if (stack.empty() || stack.back() != '[') {
				cout << 0;
				return 0;
			}
			if (s[i - 1] == '[') ans += temp;
			temp /= 3;
			stack.pop_back();
			break;
		default:
			cout << 0;
			return 0;
		}
	}
	if (!stack.empty()) cout << 0;
	else cout << ans;
}