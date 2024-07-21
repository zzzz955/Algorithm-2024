#include <iostream>

using namespace std;

int main() {
	int m = 2, d = 18, im, id;
	cin >> im >> id;
	if (m == im && d == id) cout << "Special";
	else if (m < im || (m == im && d < id)) cout << "After";
	else cout << "Before";
}