#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int limit, flag = 0;
string a, b;

void bt(int level) {
	if (flag) return;
	if (level == limit) {
		if (a == b) {
			flag = 1;
			return;
		}
	}
	if (b[0] == 'B') {
		reverse(b.begin(), b.end());
		b.erase(b.end() - 1);
		bt(level + 1);
		b += 'B';
		reverse(b.begin(), b.end());
	}
	if (b[b.size() - 1] == 'A') {
		b.erase(b.end() - 1);
		bt(level + 1);
		b += 'A';
	}
}

int main() {
	cin >> a >> b;
	limit = b.size() - a.size();
	bt(0);
	if (flag) cout << 1;
	else cout << 0;
}