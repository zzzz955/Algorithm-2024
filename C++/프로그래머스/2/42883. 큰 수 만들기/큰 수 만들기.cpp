#include <bits/stdc++.h>

using namespace std;

int v[1000000];

string solution(string number, int k) {
    int n = number.size();
    deque<char> stack;
    for (int i = 0; i < n; i++) {
        while (!stack.empty() && stack.back() < number[i] && k) {
            stack.pop_back();
            k--;
        }
        stack.push_back(number[i]);
    }
    while (k--) stack.pop_back();
    
    string s = "";
    for (const char& ch : stack) s += ch;
    
    return s;
}