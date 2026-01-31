#include<bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>>adj[n+1];
    vector<long long>mini(n+1);
    vector<long long>maxi(n+1);
    vector<long long>ans(n+1);
    for(long long i=0;i<m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    pq.push({0,1});
    long long dis[n+1];
    for(long long i=0;i<n+1;i++)
    {
        dis[i]=LLONG_MAX;
        mini[i]=LLONG_MAX;
        maxi[i]=0;
        ans[i]=0;
    }
    dis[1]=0;
    mini[1]=0;
    ans[1]=1;
    while(!pq.empty())
    {
        long long node=pq.top().second;
        long long distance=pq.top().first;
        pq.pop();
        if(distance>dis[node])continue;
        for(auto it:adj[node])
        {
            long long wt=it.second;
            long long child=it.first;
            long long total= distance+wt;
            if(total>dis[child])continue;
            else if(total==dis[child])
            {
                ans[child]+=ans[node];
                ans[child]%=mod;
                mini[child]=min(mini[node]+1,mini[child]);
                maxi[child]=max(maxi[node]+1,maxi[child]);

            }
            else if(total<dis[child])
            {
                dis[child]=total;
                pq.push({total,child});
                ans[child]=ans[node];
                mini[child]=mini[node]+1;
                maxi[child]=maxi[node]+1;

            }

        }
    }
    cout<<dis[n]<<" "<<ans[n]<<" "<<mini[n]<<" "<<maxi[n]<<endl;
}

