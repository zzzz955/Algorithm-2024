#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int LOG = 31;
int n, ans;

struct Trie {
    Trie* child[2];
    Trie() {
        memset(child, 0, sizeof(child));
    }
};

void Insert(Trie* node, const string& str) {
    Trie* cur = node;
    for (int i = 0; i < LOG; i++) {
        int idx = str[i] - '0';
        if (!cur->child[idx]) cur->child[idx] = new Trie();
        cur = cur->child[idx];
    }
}

void Query(Trie* node, const string& str, int temp) {
    Trie* cur = node;
    for (int i = 0; i < LOG; i++) {
        int idx = str[i] - '0';

        if (cur->child[idx ^ 1]) {
            temp += pow(2, LOG - i - 1);
            cur = cur->child[idx ^ 1];
            continue;
        }

        if (!cur->child[idx]) {
            cur->child[idx] = new Trie();
            temp += pow(2, LOG - i - 1);
        }

        cur = cur->child[idx];
    }
    ans = max(ans, temp);
}

string getBit(int n) {
    string s = "";
    for (int i = LOG - 1; i >= 0; i--) {
        if ((n >> i) & 1) s += '1';
        else s += '0';
    }
    return s;
}

int main() {
    Trie* root = new Trie();
    int first;
    cin >> n >> first;

    string f = getBit(first);
    Insert(root, f);

    ans = 0;
    while (--n) {
        int num; cin >> num;
        string s = getBit(num);
        Insert(root, s);
        Query(root, s, 0);
    }

    cout << ans;
}