#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, d, e, i;
	cin >> a >> b >> c >> d >> e;
	cout << min(a, min(b, c)) + min(d, e) - 50;
}