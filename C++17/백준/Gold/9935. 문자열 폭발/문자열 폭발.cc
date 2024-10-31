#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s, b;
int n, m;
vector<char> stack;

bool chk() {
	int idx = 0;
	int len = stack.size();
	for (int i = len - 1; i >= len - m; i--) {
		if (stack[i] != b[idx++]) return false;
	}
	
	return true;
}

void bomb() {
	while (stack.size() >= m && stack.back() == b[0]) {
		if (chk()) {
			int temp = m;
			while (temp--) stack.pop_back();
		}
		else break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> b;

	reverse(b.begin(), b.end());
	n = s.size(), m = b.size();
	for (int i = 0; i < n; i++) {
		bomb();
		stack.push_back(s[i]);
	}
	bomb();

	if (stack.empty()) cout << "FRULA";
	else for (const char& ch : stack) cout << ch;
}