#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int a, b, tc = 0;
	string op, ans;
	bool flag = false;
	while (++tc) {
		cin >> a >> op >> b;
		if (op == "E") break;
		if (op == ">") flag = a > b;
		if (op == ">=") flag = a >= b;
		if (op == "<") flag = a < b;
		if (op == "<=") flag = a <= b;
		if (op == "==") flag = a == b;
		if (op == "!=") flag = a != b;
		cout << "Case " << tc << ": " << (flag?"true":"false") << "\n";
	}
}