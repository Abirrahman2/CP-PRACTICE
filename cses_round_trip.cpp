#include<bits/stdc++.h>
using namespace std;
int ending=-1;
int start=-1;
bool dfs(int i,int track,int p[],int vis[],vector<int>adj[])
{
    vis[i]=1;
    p[i]=track;
    for(auto it:adj[i])
    {
        if(track!=it && vis[it]==1)
        {
            start=it;
            ending=i;
            return true;
        }
        else{
            if(track!=it && vis[it]==0)
            {
               if(dfs(it,i,p,vis,adj))
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
        int arr[n];
        vector<int>adj[n+1];
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int p[n+1]={0};
        int vis[n+1]={0};
        bool track2=false;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,-1,p,vis,adj))
                {
                    track2=true;
                    //start=i;
                    break;
                }

            }
        }

        vector<int>ans;
        if(track2==true)
        {
           // cout<<ending<<endl;
           // cout<<start<<endl;

            ans.push_back(start);
            ans.push_back(ending);
            while(p[ending]!=start)
            {
                ans.push_back(p[ending]);
                ending=p[ending];
            }
            ans.push_back(start);
            cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }

    }
}

