#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int d, m;
	cin >> d >> m;
	vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<string> day = { "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
	int sum = 0;
	while (--m) {
		sum += months[m - 1];
	}
	sum += d;
	cout << day[sum % 7];
}