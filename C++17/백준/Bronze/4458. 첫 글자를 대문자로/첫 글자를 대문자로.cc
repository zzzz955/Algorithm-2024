#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string a;
		getline(cin, a);
		if (a[0] >= 97) a[0] += 'A' - 'a';
		cout << a << "\n";
	}
}