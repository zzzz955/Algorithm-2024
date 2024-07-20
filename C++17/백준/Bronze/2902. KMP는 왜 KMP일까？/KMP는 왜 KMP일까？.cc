#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string a;
	cin >> a;
	string ans = "";
	string temp = "temp";
	stringstream ss(a);
	while (getline(ss, temp, '-')) {
		ans += temp[0];
	}
	cout << ans;
}