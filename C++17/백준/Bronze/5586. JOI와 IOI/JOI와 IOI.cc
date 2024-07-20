#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int joi = 0, ioi = 0;
	int pos = s.find("JOI");
	while (pos != s.npos) {
		joi++;
		pos = s.find("JOI", pos + 1);
	}
	pos = s.find("IOI");
	while (pos != s.npos) {
		ioi++;
		pos = s.find("IOI", pos + 1);
	}
	cout << joi << "\n" << ioi;
}