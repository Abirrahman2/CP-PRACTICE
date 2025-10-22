#include<bits/stdc++.h>
using namespace std;
int fun(int node,vector<int>adj[],vector<int>&dp)
{
    if(adj[node].size()==0)
    {
       dp[node]=0;
       return 1;
    }

    int count=0;
    for(auto it:adj[node])
    {
        dp[node]=dp[node]+fun(it,adj,dp);
    }
    return 1+dp[node];
}
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=2;i<=n;i++)
    {
        int u;
        cin>>u;
        adj[u].push_back(i);

    }
    vector<int>dp(n+1,0);
    int val=fun(1,adj,dp);
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }

}

