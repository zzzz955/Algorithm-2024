#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		cout << i << ". " << s << "\n";
	}
}