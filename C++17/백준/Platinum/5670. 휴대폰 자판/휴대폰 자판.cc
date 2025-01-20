#include<iostream>
#include<cstring>
using namespace std;

int n, idx;
struct Trie {
	Trie* child[26];
	int cnt;
	bool isEnd;
	Trie() {
		memset(child, 0, sizeof(child));
		cnt = 0;
		isEnd = false;
	}
};
Trie* memory[555555];
string lst[100000];

void insert(Trie* root, const string& str) {
	Trie* cur = root;
	for (const char& ch : str) {
		int index = ch - 'a';
		if (!cur->child[index]) cur->child[index] = memory[idx++] = new Trie();
		cur = cur->child[index];
		cur->cnt++;
	}
	cur->isEnd = true;
}

int query(Trie* root, const string& str) {
	int result = 1;
	Trie* cur = root->child[str[0] - 'a'];
	int cnt = cur->cnt;
	for (int i = 1; i < str.size(); ++i) {
		int index = str[i] - 'a';
		cur = cur->child[index];
		if (cnt != cur->cnt) {
			result++;
			cnt = cur->cnt;
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n) {
		idx = 0;
		Trie* root = memory[idx++] = new Trie();
		for (int i = 0; i < n; ++i) {
			cin >> lst[i];
			insert(root, lst[i]);
		}

		int total = 0;
		for (int i = 0; i < n; ++i) {
			total += query(root, lst[i]);
		}
		printf("%.2f\n", (double)total / n);

		for (int i = 0; i < idx; ++i) delete memory[i];
	}
}