#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    int wt[n];
    int cost[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=w;i++)
    {
        if(wt[n-1]<=i)
        {
            dp[n-1][i]=cost[n-1];
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<=w;j++)
        {
            int pick=0;
            int notpick=0;
            if(wt[i]<=j)
            {
                pick=cost[i]+dp[i+1][j-wt[i]];
            }
            notpick=dp[i+1][j];
            dp[i][j]=max(pick,notpick);
        }
    }
    cout<<dp[0][w]<<endl;
}

