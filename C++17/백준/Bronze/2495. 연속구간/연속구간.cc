#include <iostream>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int a_max = 0, b_max = 0, c_max = 0;
	int a_len = 1, b_len = 1, c_len = 1;
	for (int i = 0; i < 7; i++) {
		if (a[i] == a[i + 1]) a_len++;
		else a_len = 1;
		if (b[i] == b[i + 1]) b_len++;
		else b_len = 1;
		if (c[i] == c[i + 1]) c_len++;
		else c_len = 1;
		a_max = max(a_max, a_len);
		b_max = max(b_max, b_len);
		c_max = max(c_max, c_len);
	}
	cout << a_max << "\n" << b_max << "\n" << c_max;
}