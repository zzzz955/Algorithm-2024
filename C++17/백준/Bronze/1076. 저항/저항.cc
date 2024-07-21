#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
	unordered_map<string, int> dic = {
		{"black", 0}, {"brown", 1}, {"red", 2},
		{"orange", 3}, {"yellow", 4}, {"green", 5},
		{"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9}
	};
	string a, b, c;
	cin >> a >> b >> c;
	long long d = dic[a], e = dic[b], f = dic[c];
	cout << (d * 10 + e) * (long long)pow(10, f);
}