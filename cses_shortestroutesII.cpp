#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<vector<long long>>adj(n+1,vector<long long>(n+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==j)
                {
                    adj[i][j]=0;
                    continue;
                }
                adj[i][j]=LLONG_MAX;
            }
        }
        for(int i=0;i<m;i++)
        {
            long long u,v,w;
            cin>>u>>v>>w;
            adj[u][v]=min(adj[u][v],w);
            adj[v][u]=min(adj[v][u],w);
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j)
                    {
                        continue;
                    }
                    if(adj[i][k]==LLONG_MAX || adj[j][k]==LLONG_MAX)
                    {
                        continue;
                    }
                    if(adj[i][j]>adj[i][k]+adj[j][k])
                    {
                        adj[i][j]=adj[i][k]+adj[j][k];
                    }
                }
            }
        }
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            if(adj[u][v]>=LLONG_MAX)
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<adj[u][v]<<endl;


        }
    }
}


