#include<bits/stdc++.h>
using namespace std;
void findLongest(int node,int par,vector<int>adj[],vector<int>&longest)
{
    longest[node]=0;
    for(auto it:adj[node])
    {
        if(it==par)continue;
        findLongest(it,node,adj,longest);
        longest[node]=max(longest[node],1+longest[it]);
    }

}
void fun(int node,int par,vector<int>adj[],vector<int>&longest,vector<int>&dp)
{
    int maxi1=-1;
    int maxi2=-1;
    for(auto it:adj[node])
    {
        if(it==par)continue;
        fun(it,node,adj,longest,dp);
        if(longest[it]>maxi1)
        {
            maxi2=maxi1;
            maxi1=longest[it];

        }
        else if(maxi2<longest[it])
        {
            maxi2=longest[it];
        }
    }

    if(maxi1==-1 && maxi2==-1)
    {
        dp[node]=0;
    }
    else{
        if(maxi2==-1 && maxi1!=-1)
        {
            dp[node]=1+maxi1;
        }
        else if(maxi1!=-1 && maxi2!=-1){
            dp[node]=maxi1+2+maxi2;
        }
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
    vector<int>longest(n+1,0);
    findLongest(1,-1,adj,longest);

    vector<int>dp(n+1,0);
    fun(1,-1,adj,longest,dp);
    int maxi=-1;
    for(int i=1;i<=n;i++)
    {
        maxi=max(maxi,dp[i]);
    }

    cout<<maxi<<endl;

}

