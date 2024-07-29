#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, m;
	map<int, int> dic;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		dic[a]++;
		dic[b]++;
	}
	for (int i = 1; i <= n; i++) {
		cout << dic[i] << "\n";
	}
}