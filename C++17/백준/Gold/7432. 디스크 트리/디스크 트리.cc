#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int n;
struct Trie {
	map<string, Trie*> child;
};

void insert(Trie* node, const vector<string>& strs) {
	Trie* cur = node;
	for (const string& str : strs) {
		if (!cur->child[str]) cur->child[str] = new Trie();
		cur = cur->child[str];
	}
}

void dfs(Trie* node, int level) {
	Trie* cur = node;
	
	for (const auto& val : cur->child) {
		for (int i = 0; i < level; i++) cout << " ";
		cout << val.first << "\n";
		dfs(val.second, level + 1);
	}
}

Trie* root = new Trie();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n--) {
		string s; cin >> s;
		stringstream ss(s);
		vector<string> dir;
		while (getline(ss, s, '\\')) dir.push_back(s);
		insert(root, dir);
	}
	dfs(root, 0);
}