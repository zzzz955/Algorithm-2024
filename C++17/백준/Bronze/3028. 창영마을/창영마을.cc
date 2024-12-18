#include<iostream>
#include<algorithm>
using namespace std;

int cups[4];
string s;

int main() {
	cin >> s;
	cups[1] = 1;
	for (const char& ch : s) {
		if (ch == 'A') swap(cups[1], cups[2]);
		else if (ch == 'B') swap(cups[2], cups[3]);
		else swap(cups[1], cups[3]);
	}
	for (int i = 1; i < 4; ++i) if (cups[i]) cout << i;
}