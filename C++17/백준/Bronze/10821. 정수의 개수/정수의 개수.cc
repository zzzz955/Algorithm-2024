#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	string a, temp;
	cin >> a;
	stringstream ss(a);
	int cnt = 0;
	while (getline(ss, temp, ',')) cnt++;
	cout << cnt;
}