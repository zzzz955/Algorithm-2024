#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	istringstream iss(s);
	int sum = 0, val;
	while (iss >> val) sum += val;
	cout << sum;
}