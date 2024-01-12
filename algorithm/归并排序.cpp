#include <iostream>
using namespace std;

void merge_sort(int* A, int l, int r, int* T)
{
    if(r - l > 1)
    {
        int m = (l + r) >> 1;
        int p = l, q = m, i = l;
        merge_sort(A, l, m, T);
        merge_sort(A, m, r, T);
        while(p < m || q < r)
        {
            if(q >= r || (p < m && A[p] <= A[q]))
                T[i++] = A[p++];
            else
                T[i++] = A[q++];
        }
        for(i = l; i < r; i++) A[i] = T[i];
    }
}


int main()
{
    int a[10], l, r, b[10];

    for(int i = 0; i < 10; i++) cin>>a[i];

    merge_sort(a, 0, 10, b);

    for(int i = 0; i < 10; i++) cout<<a[i]<<" ";

    return 0;
}
