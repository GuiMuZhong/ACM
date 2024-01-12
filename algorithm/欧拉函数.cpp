long long Eul(long n)
{
    long long ret = n, i;

    for (i = 2; i * i <= n; i++)        //i * i 节省时间
    {
        if (n % i == 0)
        {
            ret = ret - ret / i;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 1)      //如果 n 本身是素数
    {
        ret = ret - ret / n;
    }

    return ret;
}
