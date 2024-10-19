#include<iostream>
#include<string>

using namespace std;

int n, m, ans;
string a, b;

int av[52];
int bv[52];

int chk() {
	for (int i = 0; i < 52; i++) if (av[i] != bv[i]) return 0;
	return 1;
}

int To_index(const char& ch) {
	if ('a' <= ch && ch <= 'z') return ch - 'a';
	return ch - 'A' + 26;
}

int main() {
	cin >> n >> m >> a >> b;

	for (int i = 0; i < n; i++) {
		av[To_index(a[i])]++;
		bv[To_index(b[i])]++;
	}

	ans += chk();

	for (int i = n; i < m; i++) {
		bv[To_index(b[i])]++;
		bv[To_index(b[i - n])]--;
		ans += chk();
	}

	cout << ans;
}