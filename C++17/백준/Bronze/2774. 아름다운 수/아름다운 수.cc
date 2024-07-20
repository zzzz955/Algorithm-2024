#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		unordered_set<int> dic;
		cin >> s;
		int length = s.size();
		while (length--) {
			dic.insert(s[length]);
		}
		cout << dic.size() << "\n";
	}
}