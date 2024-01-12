#include <isotream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 10000 + 5;
vector<int> g[maxn];
int du[maxn], n, m, L[maxn];

bool toposort()
{
    memset(du, 0, sizeof(du));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g[i].size(); j++){
            du[g[i][j]]++;
        }
    }
    int tot = 0;
    queue<int> Q;
    for(int i = 0; i < n; i++) if(!du[i]) Q.push(i);
    while(!Q.empty()){
        int x = Q.front(); Q.pop();
        L[tot++] = x;
        for(int i = 0; i < g[x].size(); i++){
            int t = g[x][i];
            du[t]--;
            if(!du[t]) q.push(t);
        }
    }

    return tot == n;
}
