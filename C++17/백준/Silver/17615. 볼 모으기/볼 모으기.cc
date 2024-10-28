#include<iostream>
#include<queue>

using namespace std;

int n;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	int Rcnt = 0, flag1 = 0, flag2 = 0;
	for (int i = n - 1; i > 0; i--) {
		if (s[i] == 'B') {
			int cnt = 0, prod = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == 'R') Rcnt++;
			}
			break;
		}
	}

	int Bcnt = 0;
	flag1 = 0, flag2 = 0;
	for (int i = n - 1; i > 0; i--) {
		if (s[i] == 'R') {
			int cnt = 0, prod = 1;
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == 'B') Bcnt++;
			}
			break;
		}
	}
	cout << min(Rcnt, Bcnt);
}