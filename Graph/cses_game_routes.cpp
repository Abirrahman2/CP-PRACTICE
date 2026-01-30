#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    vector<ll>indegree(n+1,0);
    vector<ll>ans(n+1,0);
    for(ll i=0;i<m;i++)
    {

        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<ll>q;
    for(ll i=2;i<=n;i++)
    {
        if(indegree[i]==0)
        {
           q.push(i);
        }
    }
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0 && it!=1)
            {
                q.push(it);
            }
        }
    }
    q.push(1);
    ans[1]=1;
    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
            ans[it]+=(ans[node]%mod);
            ans[it]%=mod;

        }
    }
  /*  for(auto it:ans)
    {
        cout<<it<<" ";
    }*/
    cout<<ans[n]<<endl;



}

