#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int t, sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> t;
		sum += t;
	}
	cout << sum / 60 << "\n" << sum % 60;
}