#include<iostream>
using namespace std;

int n, k;
int v[1001];

int main() {
	cin >> n >> k;
	int idx = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (v[j]) continue;
			v[j] = 1;
			idx++;
			if (idx == k) {
				cout << j;
				return 0;
			}
		}
	}
}