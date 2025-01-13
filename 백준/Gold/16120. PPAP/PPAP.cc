#include<iostream>
#include<vector>
using namespace std;

string s, stack;

void PPAP() {
	while (stack.size() >= 4 && string(stack.end() - 4, stack.end()) == "PPAP") {
		int len = 4;
		while (len--) stack.pop_back();
		stack += 'P';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		stack += s[i];
		PPAP();
	}
	PPAP();
	if (stack == "P") cout << "PPAP";
	else cout << "NP";
}