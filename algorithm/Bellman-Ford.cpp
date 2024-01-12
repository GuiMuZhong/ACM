#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxe = 1000;
const int maxv = 1000;

struct edge
{
    int from;
    int to;
    int cost;
};

edge es[maxe];
int d[maxv];
int v, e;

void shortest_path(int s)
{
    fill(d, d + v, INF);
    d[s] = 0;
    while(true){
        bool update = false;
        for(int i = 0; i < e; i++){
            edge ei = es[i];
            if(d[ei.from] != INF && d[ei.to] > d[ei.from] + ei.cost){
                d[ei.to] = d[ei.from] + ei.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

int main()
{
    return 0;
}
