#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 10000;
int n, k;
int pa[maxn], ra[maxn];

void init(int n)
{
    for(int i = 0; i < n; i++){
        pa[i] = i;
        ra[i] = 0;
    }
}

int find_set(int x)
{
    return pa[x] == x ? x : pa[x] = find_set(pa[x]);
}

void unite(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y) return;

    if(ra[x] < ra[y]){
        pa[x] = y;
    }
    else{
        pa[y] = x;
        if(ra[x] == ra[y]) ra[x]++;
    }
}

bool same(int x, int y)
{
    return find_set(x) == find_set(y);
}
