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

bool find_negative_loop()
{
    fill(d, d + v, 0);
    for(int i = 0; i < v; i++){
        for(int j = 0; j < e; j++){
            edge ei = es[j];
            if(d[ei.to] > d[ei.from] + ei.cost){
                d[ei.to] = d[ei.from] + ei.cost;
                if(i == v - 1) return true;
            }
        }
    }

    return false;
}

int main()
{
    return 0;
}
