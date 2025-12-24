#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int max_n = 1000000;
int Tree[max_n<<2];
int A[max_n];

void Build(int l, int r, int rt) 
{
    if (l == r){
        scanf("%d", &Tree[rt]);
        return;
    }
    int mid = (l + r) >> 1;

    Build(l, mid, rt<<1);
    Build(mid + 1, r, rt<<1|1);

    Tree[rt] = max(Tree[rt<<1], Tree[rt<<1|1]);
}

void Update(int pos, int val, int l, int r, int rt) 
{
    if(l == r){
        Tree[rt] = val;
        return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid) Update(pos, val, l, mid, rt<<1);
    else Update(pos, val, mid +1, r, rt<<1|1);

    Tree[rt] = max(Tree[rt<<1], Tree[rt<<1|1]);
}

int Query(int L, int R, int l, int r, int rt) 
{
    if(L <= l && R >= r) return Tree[rt];

    int mid = (l + r) >> 1;
    int ans = 0;

    if (L <= mid) ans = max(ans, Query(L, R, l, mid, rt<<1));
    if (R > mid) ans = max(ans, Query(L, R, mid+1, r, rt<<1|1));

    return ans;
}
