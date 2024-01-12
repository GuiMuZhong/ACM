#include <iostream>
using namespace std;

void subset(int n, int s)
{
    for(int i = 0; i < n; i++){
        if(s & (1 << i)) cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    while(cin>>n){
        for(int i = 0; i < (1 << n); i++){
            subset(n, i);
        }
    }
    return 0;
}
