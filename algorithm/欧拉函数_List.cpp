long long phi[100001000];

void Eul_list(long long n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++) phi[i] = 0;

    for (int i = 2; i <= n; i++){
        if (phi[i] == 0){
            for (int j = i; j <= n; j += i){
                if (phi[j] == 0) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
