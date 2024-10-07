#include<iostream>
#include<cstring>
#include<unordered_map>
#include<string>

using namespace std;
int c, n, q;
unordered_map<string, int> teams;

struct Trie {
	Trie* child[26];
	bool isEnd;
	Trie() {
		memset(child, 0, sizeof(child));
		isEnd = false;
	}
};

void insert(Trie* node, const string& str) {
	Trie* cur = node;
	for (const char& ch : str) {
		int idx = ch - 'a';
		if (!cur->child[idx]) cur->child[idx] = new Trie();
		cur = cur->child[idx];
	}	
	cur->isEnd = true;
}

bool query(Trie* node, const string& str) {
	Trie* cur = node;
	for (int i = 0; i < str.size(); i++) {
		int idx = str[i] - 'a';
		if (cur->isEnd && teams[string(str.begin() + i, str.end())]) return true;
		else if (!cur->child[idx]) return false;
		cur = cur->child[idx];
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Trie* root = new Trie();
	cin >> c >> n;
	for (int i = 0; i < c; i++) {
		string s; cin >> s;
		insert(root, s);
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		teams[s] = 1;
	}
	cin >> q;
	while (q--) {
		string s; cin >> s;
		if (query(root, s)) cout << "Yes\n";
		else cout << "No\n";
	}
}