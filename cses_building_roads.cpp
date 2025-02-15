#include<bits/stdc++.h>
using namespace std;
//vector<int>adj[11];
void dfs(int node,int vis[],vector<int>adj[])
{
    vis[node]=1;
    //v.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>v;
    int vis[n+1];
    for(int i=0;i<n+1;i++)
    {
        vis[i]=0;
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,vis,adj);
            count++;
            v.push_back(i);
        }
    }
    cout<<count-1<<endl;
    for(int i=0;i<v.size()-1;i++)
    {
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
}
