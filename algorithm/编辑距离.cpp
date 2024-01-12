#include <iostream>
#include <string>
using namespace std;

const int maxn = 1000 + 10;
int dp[maxn][maxn];

int main()
{
    string a, b;
    cin>>a>>b;
    int A = a.length();
    int B = b.length();

    for(int i = 0; i <= A; i++) dp[i][0] = i;
    for(int i = 0; i <= B; i++) dp[0][i] = i;
    for(int i = 1; i <= A; i++)
    {
        for(int j = 1; j <= B; j++)
        {
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j -1])) + 1;
        }
    }

    cout<<dp[A][B]<<endl;

    return 0;
}
