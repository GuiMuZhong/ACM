long long mod_pow(long long x, long long n, long long mod)
{
    long long res = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }

    return res;
}
