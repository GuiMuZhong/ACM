long long Eul(long n)
{
    long long ret = n, i;

    for (i = 2; i * i <= n; i++)        //i * i ��ʡʱ��
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
    if (n > 1)      //��� n ����������
    {
        ret = ret - ret / n;
    }

    return ret;
}
