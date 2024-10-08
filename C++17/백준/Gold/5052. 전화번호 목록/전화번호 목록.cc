#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
int tc, n;
string lst[10000];

struct Trie {
	Trie* child[10];
	bool isEnd;
	Trie() {
		memset(child, 0, sizeof(child));
		isEnd = false;
	}
};

bool insert(Trie* node, const string& str) {
	Trie* cur = node;
	for (const char& ch : str) {
		int idx = ch - '0';
		if (cur->isEnd) return false;
		else if (!cur->child[idx]) cur->child[idx] = new Trie();
		cur = cur->child[idx];
	}
	cur->isEnd = true;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		Trie* root = new Trie();

		for (int i = 0; i < n; i++) cin >> lst[i];
		sort(lst, lst + n);

		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (flag) flag = insert(root, lst[i]);
			else break;
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
}