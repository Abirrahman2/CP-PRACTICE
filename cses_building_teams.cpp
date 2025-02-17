#include<bits/stdc++.h>
using namespace std;
bool bfs(int i,int vis[],int color[],vector<int>adj[])
{
    queue<int>q;
    q.push(i);
    vis[i]=1;
    color[i]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
               color[it]=1-color[node];
                vis[it]=1;
                q.push(it);
            }
            else{
            if(color[it]==color[node])
            {
                return true;
            }

            }

        }
    }
    return false;
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
        vector<int>adj[n+1];
        int arr[n+1]={0};
        int brr[n+1]={0};
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       int vis[n+1]={0};
       int color[n+1];
       for(int i=0;i<=n;i++)
       {
           color[i]=-1;
       }
       bool track=false;
       for(int i=1;i<=n;i++)
       {
           if(vis[i]==0)
           {
            if(bfs(i,vis,color,adj)==true)
           {
               cout<<"IMPOSSIBLE"<<endl;
               track=true;
               break;
           }

           }

       }
       if(track==false)
       {
       for(int i=1;i<=n;i++)
       {
           cout<<color[i]+1<<" ";
       }
       cout<<endl;

       }

    }
}
