long long Extgcd(long long a, long long b, long long& x, long long& y)    //��չŷ�����
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

long long China_Remainder(long long r[], long long m[], long long n)    //�й���������   R[]���������m[]��ų�����n�Ǹ���
{
    long long i, d, x, y, Mi, M = 1, ret = 0;

    for (i = 0; i < n; i++)
    {
        M *= m[i];
    }
    for (i = 0; i < n; i++)
    {
        Mi = M / m[i];
        d = Extgcd(m[i], Mi, x, y);
        ret = (ret + y * Mi * r[i]) % M;
    }

    return ret > 0 ? ret : ret + M;
}
