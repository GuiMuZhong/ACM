#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int max_n = 100000+10;
ll Tree[max_n<<2];
ll Add [max_n<<2];      //延迟更新标记
ll A[max_n];

void build(int l, int r, int rt)        //建树
{
    if (l == r){
        scanf("%I64d", &Tree[rt]);
        return;
    }

    int mid = (l + r) >> 1;

    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);

    Tree[rt] = Tree[rt<<1] + Tree[rt<<1|1];
}

void PushDown(int rt, int l, int r)         //下推标记
{
    if (Add[rt])
    {
        Tree[rt<<1] += Add[rt] * ((l + r) / 2 - l + 1 );    //(l + r) / 2 就是 mid
        Tree[rt<<1|1] += Add[rt] * (r - (l + r) / 2);

        Add[rt<<1] += Add[rt];
        Add[rt<<1|1] += Add[rt];

        Add[rt] = 0;
    }
}

void update(int L, int R, int val, int l, int r, int rt)        //区间更新
{
    if (L <= l && R >= r)
    {
        Add[rt] += val;
        Tree[rt] += (r - l +1) * val;
        return;
    }

    PushDown(rt, l, r);

    int mid = (l + r) >> 1;

    if(L <= mid)
    {
        update(L, R, val, l, mid, rt<<1);
    }
    if(mid  < R)
    {
        update(L, R, val, mid+1, r, rt<<1|1);
    }

    Tree[rt] = Tree[rt<<1]+Tree[rt<<1|1];       //向上更新
}

ll query(int L, int R, int l, int r, int rt)        //查询
{
    if (L <= l && R >= r)
    {
        return Tree[rt];
    }
    PushDown(rt, l, r);

    int mid = (l + r) >> 1;
    ll ans = 0;

    if(L <= mid)
    {
        ans += query(L, R, l, mid, rt<<1);
    }
    if(R > mid)
    {
        ans += query(L, R, mid+1, r, rt<<1|1);
    }

    return ans;
}

int main()
{
    int N, Q, i, a, b, c;
    char s[5];

    scanf("%d %d", &N, &Q);

    for (i = 1; i<= N; i++)
    {
        scanf("%lld", &A[i]);
    }
    build(1, N, 1);

    memset(Add, 0, sizeof(Add));        //标记初始化

    while(Q--)
    {
        scanf("%s %d %d", s, &a, &b);

        if(s[0] == 'Q')
        {
            printf("%lld\n", query(a, b, 1, N, 1));
        }
        else
        {
            scanf("%d", &c);

            update(a, b, c, 1, N, 1);
        }
    }

    return 0;
}
