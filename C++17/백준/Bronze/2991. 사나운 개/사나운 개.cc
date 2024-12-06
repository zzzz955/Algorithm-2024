#include<iostream>
using namespace std;

struct Dog {
	int atk, rst;
};
Dog d1, d2;
int p, m, n;

void chk(int e) {
	int result = 0;
	int dog1 = e % (d1.atk + d1.rst);
	int dog2 = e % (d2.atk + d2.rst);
	if (0 < dog1 && dog1 <= d1.atk) result++;
	if (0 < dog2 && dog2 <= d2.atk) result++;
	cout << result << "\n";
}

int main() {
	cin >> d1.atk >> d1.rst >> d2.atk >> d2.rst >> p >> m >> n;
	
	chk(p);
	chk(m);
	chk(n);
}