#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 10;

class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    void BFS(int x, int y, vector<vector<char>>& g) {
        if(g[x][y] != '1') return;

        queue<pair<int, int>> Q;

        Q.push({x, y});
        g[x][y] = '0';

        while(!Q.empty()) {
            pair<int, int> p = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == '1') {
                    Q.push({x, y});
                    g[x][y] = '0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    BFS(i, j, grid);
                }
            }
        }

        return ans;
    }
};

int main() {

    return 0;
}