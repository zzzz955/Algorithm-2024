#include <iostream>

using namespace std;

int main() {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	int word = a / c, math = b / d;
	if (a % c)word++;
	if (b % d)math++;
	int ans = l - max(word, math);
	cout << ans;
}