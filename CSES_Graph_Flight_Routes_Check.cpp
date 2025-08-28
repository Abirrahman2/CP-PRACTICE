#include<bits/stdc++.h>
using namespace std;
void topoSort(int node,int vis[],vector<int>adj[],stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            topoSort(it,vis,adj,st);
        }
    }
    st.push(node);
}
void dfs(int node,int vis[],vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            dfs(it,vis,adj);
        }
    }
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
       for(int i=0;i<m;i++)
       {
           int u,v;
           cin>>u>>v;
           adj[u].push_back(v);
       }
       int vis[n+1]={0};
       stack<int>st;
       for(int i=1;i<=n;i++)
       {
           if(vis[i]==0)
           {
               topoSort(i,vis,adj,st);
           }
       }
       vector<int>adjT[n+1];
       for(int i=1;i<=n;i++)
       {
           for(auto it:adj[i])
           {
               adjT[it].push_back(i);
           }
       }
       int ssc=0;
       int visT[n+1]={0};
       int track=-1;
       int parent=-1;
       while(!st.empty())
       {
           int node=st.top();
           st.pop();
           if(visT[node]==0 && ssc==0)
           {
               ssc++;
               parent=node;
               dfs(node,visT,adjT);
           }
           else if(visT[node]==0 && ssc!=0)
           {
               ssc++;
               track=node;
               break;
           }

       }
       if(track!=-1)
       {
           cout<<"NO"<<endl;
           cout<<track<<" "<<parent<<endl;
       }
       else{
        cout<<"YES"<<endl;
       }

    }
}

