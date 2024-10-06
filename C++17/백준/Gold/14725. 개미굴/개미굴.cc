#include<iostream>
#include<map>
#include<vector>

using namespace std;
struct Trie {
	map<string, Trie*> child;
};

void insert(Trie* node, const vector<string>& foods) {
	Trie* cur = node;
	for (const string& food : foods) {
		if (cur->child.find(food) == cur->child.end()) cur->child[food] = new Trie();
		cur = cur->child[food];
	}
}

void dfs(Trie* node, int level) {
	for (const auto& child : node->child) {
		for (int i = 0; i < level; i++) cout << "--";
		cout << child.first << "\n";
		dfs(child.second, level + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	Trie* root = new Trie();
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		vector<string> foods(a);
		for (int j = 0; j < a; j++) cin >> foods[j];
		insert(root, foods);
	}
	dfs(root, 0);
}