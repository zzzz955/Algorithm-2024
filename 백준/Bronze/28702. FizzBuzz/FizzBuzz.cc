#include <iostream>
#include <string>
using namespace std;

int to_int(string s) {
	if (s == "FizzBuzz") return -15;
	if (s == "Fizz") return -3;
	if (s == "Buzz") return -5;
	return stoi(s);
}

string to_str(int n) {
	if (n % 3 == 0 && n % 5 == 0) return "FizzBuzz";
	if (n % 3 == 0) return "Fizz";
	if (n % 5 == 0) return "Buzz";
	else return to_string(n);
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	int d = to_int(a);
	int e = to_int(b);
	int f = to_int(c);
	int ans;
	if (d >= 0) ans = d + 3;
	if (e >= 0) ans = e + 2;
	if (f >= 0) ans = f + 1;
	cout << to_str(ans);
}