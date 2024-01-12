#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxv = 10000;

struct edge
{
    int to;
    int cost;
};

typedef pair<int, int> P;

int V;
vector<edge> G[maxv];
int d[maxv];

void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > Q;
    fill(d, d + V, INF);
    d[s] = 0;
    Q.push(P(0, s));

    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i = 0 ; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                Q.push(P(d[e.to], e.to));
            }
        }
    }
}


int main()
{

    return 0;
}
