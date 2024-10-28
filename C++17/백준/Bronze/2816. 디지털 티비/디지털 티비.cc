#include<iostream>
#include<algorithm>
using namespace std;

int n, kbs1, kbs2;
string lst[100], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
		if (lst[i] == "KBS1") kbs1 = i;
		if (lst[i] == "KBS2") kbs2 = i;
	}

	int cur = 0;
	int move = kbs1;
	if (kbs2 < kbs1) kbs2++;
	while (move--) ans += '1';
	cur = kbs1;
	while (cur--) ans += '4';
	move = kbs2;
	while (move--) ans += '1';
	cur = kbs2;
	while (cur-- != 1) ans += '4';
	cout << ans;
}