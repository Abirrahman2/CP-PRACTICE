#include<bits/stdc++.h>
using namespace std;
const long long INF=-1e18;
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        long long n,m;
        cin>>n>>m;
        vector<vector<long long>>adj;
        long long dis[n+1];
        long long parent[n+1];
        for(long long i=1;i<=n;i++)
        {
            dis[i]=0;
            parent[i]=i;
        }
        dis[1]=0;
        for(int i=1;i<=m;i++)
        {
           long long u,v,w;

           cin>>u>>v>>w;
           adj.push_back({u,v,w});
        }

        for(long long i=1;i<=n-1;i++)
        {
            for(auto it:adj)
            {
                long long u=it[0];
                long long v=it[1];
                long long w=it[2];
                if(dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;
                    parent[v]=u;

                }
            }
        }
//        for(int i=1;i<=n;i++)
//        {
//            cout<<dis[i]<<" ";
//        }
//        cout<<endl;
        long long sum=0;
        bool track=false;
        long long node=-1;
        for(auto it:adj)
        {
            long long u=it[0];
            long long v=it[1];
            long long w=it[2];
            if(dis[u]+w<dis[v])
            {
                parent[v]=u;
                node=v;
                track=true;

            }
        }
        if(track==true)
        {

            for(long long i=1;i<=n-1;i++)
            {
                node=parent[node];
            }
            vector<long long>ans;
         long long x=node;
        while(x!=parent[node])
        {
            ans.push_back(node);
            node=parent[node];
        }

        ans.push_back(node);
        ans.push_back(parent[node]);
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        }
        else{
            cout<<"NO"<<endl;
        }


    }
}


