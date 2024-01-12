#include <bits/stdc++.h>
using namespace std;

const int max_n = 1e4 + 10;

int prime[max_n];
int is_prime[max_n+1];

int sieve(int n)
{
    int p = 0, i, j;

    for (i = 0; i <= n; i++)
    {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;

    for (i = 2; i <= n; i++)
    {
        if(is_prime[i])
        {
            prime[p++] = i;
            for (j = 2 * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }

    }

    return p;               //ËØÊý¸öÊý
}

int main()
{
    int num = sieve(max_n);
    cout<<num<<" "<<prime[num-1]<<endl;
    return 0;
}
