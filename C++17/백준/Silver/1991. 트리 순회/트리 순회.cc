#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<char, pair<char, char>> dic;

void dfs1(char index, vector<int> v) {
	char left = dic[index].first, right = dic[index].second;
	cout << index;
	if (left != '.' && !v[left]) {
		v[left] = 1;
		dfs1(left, v);
	}
	if (right != '.' && !v[right]) {
		v[right] = 1;
		dfs1(right, v);
	}
}

void dfs2(char index, vector<int> v) {
	char left = dic[index].first, right = dic[index].second;
	if (left != '.' && !v[left]) {
		v[left] = 1;
		dfs2(left, v);
	}
	cout << index;
	if (right != '.' && !v[right]) {
		v[right] = 1;
		dfs2(right, v);
	}
}

void dfs3(char index, vector<int> v) {
	char left = dic[index].first, right = dic[index].second;
	if (left != '.' && !v[left]) {
		v[left] = 1;
		dfs3(left, v);
	}
	if (right != '.' && !v[right]) {
		v[right] = 1;
		dfs3(right, v);
	}
	cout << index;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		dic[a] = { b, c };
	}
	vector<int> v(100, 0);
	dfs1('A', v);
	cout << "\n";
	dfs2('A', v);
	cout << "\n";
	dfs3('A', v);
}
