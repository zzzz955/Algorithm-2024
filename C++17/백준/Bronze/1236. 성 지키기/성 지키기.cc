#include<iostream>
using namespace std;
string lst[50];
int row[50], col[50] = {0,};
int n, m, ans = 1e9, cnt1 = 0, cnt2 = 0;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		for (int j = 0; j < m; j++) {
			if (lst[i][j] == 'X') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) if (!row[i]) cnt1++;
	for (int i = 0; i < m; i++) if (!col[i]) cnt2++;
	cout << max(cnt1, cnt2);
}