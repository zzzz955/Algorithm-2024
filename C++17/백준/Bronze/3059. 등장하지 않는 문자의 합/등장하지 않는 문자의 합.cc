#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int t, length, sum;
	cin >> t;
	while (t--) {
		cin >> s;
		sum = 0;
		length = abc.size();
		while (length--) {
			if (s.find(abc[length]) == s.npos) sum += abc[length];
		}
		cout << sum << "\n";
	}	
}