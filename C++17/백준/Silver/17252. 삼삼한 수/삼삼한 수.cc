#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int n; cin >> n;

	if (!n) {
		cout << "NO";
		return 0;
	}

	string s = "";
	while (n) {
		s += n % 3 + '0';
		n /= 3;
	}

	if (s.find('2') == s.npos) cout << "YES";
	else cout << "NO";
}