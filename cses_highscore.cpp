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
            dis[i]=LLONG_MAX;
            parent[i]=i;
        }
        dis[1]=0;
        for(int i=1;i<=m;i++)
        {
           long long u,v,w;

           cin>>u>>v>>w;

           w=-1LL*w;

           adj.push_back({u,v,w});
        }

        for(long long i=1;i<=n-1;i++)
        {
            for(auto it:adj)
            {
                long long u=it[0];
                long long v=it[1];
                long long w=it[2];
                if(dis[u]!=LLONG_MAX && dis[u]+w<dis[v])
                {
                    dis[v]=dis[u]+w;

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
        for(long long i=1;i<=n-1;i++)
        {
             for(auto it:adj)
             {
                long long u=it[0];
                long long v=it[1];
                long long w=it[2];
                if(dis[u]!=LLONG_MAX  && dis[u]+w<dis[v])
                {
                   //cout<<v<<endl;
                   dis[v]=INF;
                   track=true;
                }

             }
        }
        if(n==1)
        {
            for(auto it:adj)
             {
                long long u=it[0];
                long long v=it[1];
                long long w=it[2];
                if(dis[u]!=LLONG_MAX  && dis[u]+w<dis[v])
                {
                   //cout<<v<<endl;
                   dis[v]=INF;
                   track=true;
                }

             }

        }
         //cout<<track<<endl;
       // long long i=n;
//        while(parent[i]!=i && track==false)
//        {
//            if(dis[i]<0)
//            {
//                sum=sum+abs(dis[i]);
//            }
//            else
//            {
//                sum=sum-dis[i];
//            }
//
//                i=parent[i];
//
//        }

        if(dis[n]==INF)
        {
             cout<<-1<<endl;
        }
        else{
            cout<<-1*dis[n]<<endl;
        }
    }
}

