#include <bits/stdc++.h>

using namespace std;

bool answer = true;

struct Trie {
    Trie* child[10] = {0,};
    bool isEnd;
    Trie() {
        isEnd = false;
    }
};

bool insert(Trie* node, const string& str) {
    Trie* cur = node;
    for (const char& ch : str) {
        int idx = ch - '0';
        if (cur->isEnd) return false;
        if (!cur->child[idx]) cur->child[idx] = new Trie();
        cur = cur->child[idx];
    }
    cur->isEnd = true;
    return true;
}

bool solution(vector<string> phone_book) {
    Trie* root = new Trie();
    sort(phone_book.begin(), phone_book.end());
    
    for (const string& p : phone_book) {
         if (!insert(root, p)) {
             answer = false;
             break;
         }
     }  
    
    return answer;
}