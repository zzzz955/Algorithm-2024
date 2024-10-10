#include<iostream>
#include<unordered_map>

using namespace std;

struct Trie {
	unordered_map<char, Trie*> child;
	int cnt;
	Trie() {
		cnt = 0;
	}
};

Trie* root = new Trie();

int n;

void insert(Trie* node, const string& str) {
	Trie* cur = node;
	int flag = 1;
	for (int i = 0; i < str.size(); i++) {
		int idx = str[i] - 'a';
		if (!cur->child[idx]) {
			if (flag) {
				flag = 0;
				cout << string(str.begin(), str.begin() + i + 1) << "\n";
			}
			cur->child[idx] = new Trie();
		}
		cur = cur->child[idx];
	}
	if (flag) {
		cout << str;
		if (cur->cnt) cout << cur->cnt + 1;
		cout << "\n";
	}
	cur->cnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		string s; cin >> s;
		insert(root, s);
	}
}