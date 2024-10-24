#include <bits/stdc++.h>

using namespace std;

struct Song{
    int val, idx;
    bool operator<(const Song& other) const {
        return val < other.val;
    }
};

struct Desc{
    string s;
    int sum;
    bool operator<(const Desc& other) const {
        return sum < other.sum;
    }
};

unordered_map<string, priority_queue<Song>> dic1;
unordered_map<string, int> dic2;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for (int i = 0; i < genres.size(); i++) {
        string s = genres[i];
        int n = plays[i];
        dic1[s].push({n, i});
        dic2[s] += n;
    }
    
    priority_queue<Desc> pq;
    for (auto dic : dic2) {
        pq.push({dic.first, dic.second});
    }
    
    while (!pq.empty()) {
        Desc desc = pq.top(); pq.pop();
        priority_queue<Song> songs = dic1[desc.s];
        
        int ML = min(2, (int)songs.size());
        while (ML--) {
            Song song = songs.top(); songs.pop();
            answer.push_back(song.idx);
        }
    }
    
    return answer;
}