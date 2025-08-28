#include<bits/stdc++.h>
using namespace std;
void topoSort(int node,int vis[],vector<pair<int,int>>adj[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it.first]==0)
        {
            topoSort(it.first,vis,adj,st);
        }
    }
    st.push(node);
}
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[v].push_back({u,1});
        }
        int vis[n+1]={0};
        stack<int>st;
        topoSort(n,vis,adj,st);
       /* for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                topoSort(i,vis,adj,st);
            }
        }*/
        vector<long long>dis(n+1);
        for(int i=0;i<=n;i++)
        {
            dis[i]=LLONG_MIN;
        }
        dis[n]=0;
        vector<int>path(n+1);
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            for(auto it:adj[node])
            {
                if(it.second+dis[node]>dis[it.first])
                {
                    dis[it.first]=it.second+dis[node];
                    path[it.first]=node;
                }
            }
        }
        if(dis[1]==LLONG_MIN)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            cout<<dis[1]+1<<endl;
            int node=1;
            while(path[node]!=n)
            {
               cout<<node<<" ";
               node=path[node];
            }
            cout<<node<<" "<<n<<endl;

        }

    }
}
