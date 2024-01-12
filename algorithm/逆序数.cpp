#include <iostream>
using namespace std;

const int maxn = 50000 + 10;
int A[maxn], T[maxn], num = 0;

void merge_sort(int x, int y)
{
    if(y - x > 1)
    {
        int m = (x + y) >> 1;
        int p = x, q = m, i = x;
        merge_sort(x, m);
        merge_sort(m, y);
        while(p < m || q < y)
        {
            if(q >= y || (p < m && A[p] <= A[q]))
                T[i++] = A[p++];
            else
            {
                T[i++] = A[q++];
                num += m - p;
            }
        }
        for(i = x; i < y; i++) A[i] = T[i];
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>A[i];
    merge_sort(0, n);
    cout<<num<<endl;
    return 0;
}
