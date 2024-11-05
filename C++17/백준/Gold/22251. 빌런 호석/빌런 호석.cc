#include<iostream>
#include<set>
using namespace std;

int k, p, len, ans;
string n, x;
string zero = "000000";

int FND[10][10] = {
	{0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
	{4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
	{3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
	{3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
	{4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
	{3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
	{2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
	{3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
	{1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
	{2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
};
set<string> dic;

void bt(int level, string s) {
	if (level == len) {
		if (s > n || s == x || s == zero) return;
		dic.insert(s);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (p >= FND[x[level] - '0'][i]) {
			p -= FND[x[level] - '0'][i];
			bt(level + 1, s + (char)(i + '0'));
			p += FND[x[level] - '0'][i];
		}
	}
}

int main() {
	cin >> n >> k >> p >> x;
	int ns = n.size();
	int xs = x.size();
	len = ns;

	string temp = "";
	for (int i = xs; i < ns; i++) temp += "0";

	x = temp + x;
	zero = string(zero.begin(), zero.begin() + len);

	bt(0, "");

	cout << dic.size();
}