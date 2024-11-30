#include<iostream>
#include<algorithm>
using namespace	std;

int m, c[4];

int main() {
	c[1] = 1;
	cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		swap(c[a], c[b]);
	}

	for (int i = 1; i <= 3; ++i) 
		if (c[i]) {
			cout << i;
			return 0;
		}
}