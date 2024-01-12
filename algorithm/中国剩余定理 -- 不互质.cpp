long long Extgcd(long long a, long long b, long long& x, long long& y)    //扩展欧几里得
{
    long long d = a;

    if (b != 0)
    {
        d = Extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1;
        y = 0;
    }

    return d;
}

long long China_Remainder(long long r[], long long m[], long long n)    //中国余数定理   R[]存放余数，m[]存放除数，n是个数
{
    long long i, d, x, y, M = m[0], R = r[0], ret = 0;

    for (i = 1; i < n; i++)
    {
        d = Extgcd(M, m[i], x, y);
        if ((r[i] - R) % d != 0)
        {
           return -1;
        }
        x = ((r[i] - R) / d * x % (m[i] / d) + (m[i] / d)) % (m[i] / d);
        R += x * M;
        M = M * m[i] / d;
        R %= M;
    }

    return R > 0 ? R : R + M;
}
