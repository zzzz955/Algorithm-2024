#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string ans = "";
		string temp;
		while (getline(ss, temp, ' ')) {
			reverse(temp.begin(), temp.end());
			ans += temp + " ";
		}
		cout << ans << "\n";
	}
}