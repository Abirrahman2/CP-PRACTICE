#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void dfs(int node, int par,vector<int>adj[],vector<vector<int>>&dp)
{
    for(auto it:adj[node])
    {
        if(it==par)continue;
        dfs(it,node,adj,dp);
        dp[node][0]=dp[node][0]+max(dp[it][0],dp[it][1]);


    }
    for(auto it:adj[node])
    {
        if(it==par)continue;
        dp[node][1]=max(dp[node][1],(1+dp[node][0]-max(dp[it][0],dp[it][1])+dp[it][0]));
    }



}
int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>>dp(n+1,vector<int>(2,0));

    dfs(1,-1,adj,dp);
    cout<<max(dp[1][0],dp[1][1])<<endl;
}

