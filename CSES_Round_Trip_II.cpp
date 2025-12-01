#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,int par,vector<int>adj[],vector<int>&vis,vector<int>&path,int &track,stack<int>&st)
{
    vis[node]=1;
    path[node]=1;
    st.push(node);
    for(auto it:adj[node])
    {
        if(vis[it]!=1)
        {
            if(dfs(it,node,adj,vis,path,track,st))return true;
        }
        else if(vis[it]==1 && path[it]==1)
        {
            st.push(it);
            track=it;
            return true;
        }


    }
    path[node]=0;
    st.pop();
    return false;
}
int main()
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
   stack<int>st;
   vector<int>vis(n+1,0);
   vector<int>path(n+1,0);
   int track=-1;
   for(int i=1;i<=n;i++)
   {
       if(vis[i]!=1)
       {
        if(dfs(i,-1,adj,vis,path,track,st))
        {
        vector<int>ans;
        //cout<<track;
        ans.push_back(st.top());
        st.pop();
        while(st.top()!=track)
        {
        ans.push_back(st.top());
        st.pop();
        }
        ans.push_back(st.top());
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
        cout<<it<<" ";
        }
        cout<<endl;
        break;
        }

        }
   }
   if(track==-1)
   {

    cout<<"IMPOSSIBLE"<<endl;

   }

}

