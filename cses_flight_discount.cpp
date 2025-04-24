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
        vector<pair<pair<long long,long long>,bool>>adj[n+1];
        for(int i=0;i<m;i++)
        {
            long long u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({{v,w},false});
            //adj[u].push_back({{v,w/2},true});
        }
        priority_queue<pair<pair<long long,long long>,bool>,vector<pair<pair<long long,long long>,bool>>,greater<pair<pair<long long,long long>,bool>>>pq;
        long long dis[n+1];
        long long sdis[n+1];
        for(int i=1;i<=n;i++)
        {
            dis[i]=LLONG_MAX;
            sdis[i]=LLONG_MAX;
        }
        dis[1]=0;
        for(auto it:adj[1])
        {
            long long v=it.first.first;
            long long w=it.first.second;
            long long c=it.second;
            dis[v]=min(w,dis[v]);
            sdis[v]=min(w/2,sdis[v]);
            pq.push({{w,v},false});
            pq.push({{w/2,v},true});
        }
        while(!pq.empty())
        {
            long long distance=pq.top().first.first;
            long long node=pq.top().first.second;
            long long c=pq.top().second;
            pq.pop();

            if(c==false)
            {
                if(distance>dis[node])
                {
                    continue;
                }
            for(auto it:adj[node])
            {
                long long child=it.first.first;
                long long weight=it.first.second;
                long long cc=it.second;
                long long sum=distance+weight;
                long long sum1=distance+(weight)/2;
                if(sum<dis[child])
                {
                    dis[child]=sum;
                    pq.push({{sum,child},false});
                }
                if(sum1<sdis[child])
                {
                    sdis[child]=sum1;
                    pq.push({{sum1,child},true});
                }

            }

            }
            else
            {
                if(distance>sdis[node])
                {
                    continue;
                }
            for(auto it:adj[node])
            {
                long long child=it.first.first;
                long long weight=it.first.second;
                long long cc=it.second;
                long long sum=distance+weight;

                 if(sum<sdis[child])
                 {
                     sdis[child]=sum;
                     pq.push({{sum,child},true});
                 }
            }


        }
        }
        cout<<sdis[n]<<" ";
    }
}

