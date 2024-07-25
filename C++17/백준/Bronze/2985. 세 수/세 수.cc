#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c) cout << to_string(a) << "+" << to_string(b) << "=" << to_string(c);
	else if (a - b == c) cout << to_string(a) << "-" << to_string(b) << "=" << to_string(c);
	else if (a * b == c) cout << to_string(a) << "*" << to_string(b) << "=" << to_string(c);
	else if (a / b == c) cout << to_string(a) << "/" << to_string(b) << "=" << to_string(c);
	else if (a == b + c) cout << to_string(a) << "=" << to_string(b) << "+" << to_string(c);
	else if (a == b - c) cout << to_string(a) << "=" << to_string(b) << "-" << to_string(c);
	else if (a == b * c) cout << to_string(a) << "=" << to_string(b) << "*" << to_string(c);
	else if (a == b / c) cout << to_string(a) << "=" << to_string(b) << "/" << to_string(c);
}
