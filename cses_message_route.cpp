#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>adj[n+1];
        int parent[n+1]={0};
        int vis[n+1]={0};
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        vis[1]=1;
        bool track=false;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(auto it:adj[node])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    parent[it]=node;
                    q.push(it);
                    if(it==n)
                    {
                        track=true;
                        break;
                    }
                }
            }
            if(track==true)
            {
                break;
            }
        }
        if(track==false)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            vector<int>path;
            int i=n;
            path.push_back(n);
            while(parent[i]!=0)
            {
                path.push_back(parent[i]);
                i=parent[i];
            }
            reverse(path.begin(),path.end());
            cout<<path.size()<<endl;
            for(auto it:path)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
}


