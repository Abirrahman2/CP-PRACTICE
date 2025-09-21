#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
const int mod=1e9 +7;
int dp[N][2];
int main()
{

    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<=N;i++)
    {
        dp[i][0]=(2LL*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1]=(4LL*dp[i-1][1] + dp[i-1][0])%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    }
}

