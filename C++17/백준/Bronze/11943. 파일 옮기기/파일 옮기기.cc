#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min(a + d, b + c);
}
