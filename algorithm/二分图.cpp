#include <iostream>
#include <vector>
using namespace std;

const int maxv = 1000;
vector<int> G[maxv];
int v;
int color[maxv];

bool dfs(int v, int c)
{
    color[v] = c;
    for(int i = 0 ; i < G[v].size(); i++){
        if(color[G[v][i]] == c) return false;
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;
}

bool judge()
{
    for(int i = 0; i < v; i++){
        if(color[i] == 0){
            if(!dfs(i, 1)) return false;
        }
    }
    return true;
}
