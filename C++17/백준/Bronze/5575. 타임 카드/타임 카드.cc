#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> lst(3);
	for (int i = 0; i < 3; i++) {
		int h1, m1, s1, h2, m2, s2;
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		lst[i] = (h2 - h1) * 3600 + (m2 - m1) * 60 + (s2 - s1);
	}
	for (int i = 0; i < 3; i++) {
		int h, m, s;
		h = lst[i] / 3600;
		lst[i] %= 3600;
		m = lst[i] / 60;
		lst[i] %= 60;
		s = lst[i];
		cout << h << " " << m << " " << s << "\n";
	}
}