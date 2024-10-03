#include<iostream>
#include<algorithm>

using namespace std;
int l, c;
char lst[16];
int v[16];

void bt(int level, string cur, int ja, int mo) {
	if (level == l) {
		if (ja >= 2 && mo >= 1) cout << cur << "\n";
		return;
	}
	for (int i = 0; i < c; i++) {
		if (v[i]) continue;
		if (!cur.empty() && cur.back() > lst[i]) continue;
		v[i] = 1;
		pair<int, int> chk = { 0, 0 };
		if (lst[i] == 'a' || lst[i] == 'e' || lst[i] == 'i' || lst[i] == 'o' || lst[i] == 'u') chk.first++;
		else chk.second++;
		bt(level + 1, cur + lst[i], ja + chk.second, mo + chk.first);
		v[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> lst[i];
	sort(lst, lst + c);
	bt(0, "", 0, 0);
}