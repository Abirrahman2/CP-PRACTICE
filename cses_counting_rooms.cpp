#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
void dfs(int i,int j,vector<vector<char>>&arr,vector<vector<int>>&vis,int n,int m)
{
    vis[i][j]=true;
    for(int x=0;x<4;x++)
    {
        if(i+dx[x]>=0 && j+dy[x]>=0 && i+dx[x]<n && j+dy[x]<m && vis[i+dx[x]][j+dy[x]]==0 && arr[i+dx[x]][j+dy[x]]=='.')
        {
            dfs(i+dx[x],j+dy[x],arr,vis,n,m);
        }
    }
}
int main()
{
    int t;
   // cin>>t;
   t=1;
    while(t--)
    {
      int n,m;
      cin>>n>>m;
      vector<vector<char>>arr(n,vector<char>(m));
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              cin>>arr[i][j];
          }
      }
      vector<vector<int>>vis(n,vector<int>(m,0));
      int count=0;

      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(vis[i][j]==0 && arr[i][j]=='.')
              {
                  dfs(i,j,arr,vis,n,m);
                  count++;
              }
          }
      }
      cout<<count<<endl;
    }
}
