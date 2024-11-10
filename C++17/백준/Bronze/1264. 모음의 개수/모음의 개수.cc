#include<iostream>
#include<string>
using namespace std;

string mo = "aeiouAEIOU";

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "#") break;
		int cnt = 0;
		for (const char& ch : s) {
			if (mo.find(ch) != -1) cnt++;
		}
		cout << cnt << "\n";
	}
}