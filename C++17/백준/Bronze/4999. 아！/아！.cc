#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int c = count(a.begin(), a.end(), 'a');
	int d = count(b.begin(), b.end(), 'a');
	if (c >= d) cout << "go";
	else cout << "no";
}