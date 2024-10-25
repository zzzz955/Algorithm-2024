#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int v[100][100];
int n, m;

struct Pos {
    int x, y;
};

int bfs(const vector<vector<int>>& maps) {
    queue<Pos> q;
    q.push({0, 0});
    memset(v, 0, sizeof(v));
    v[0][0] = 1;
    
    while(!q.empty()) {
        Pos pos = q.front(); q.pop();
        int cx = pos.x, cy = pos.y;
        if (cx == n - 1 && cy == m - 1) return v[cx][cy];
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny] && maps[nx][ny]) {
                v[nx][ny] = v[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = bfs(maps);
    
    return answer;
}