#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
string track="ULDR";

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
     vector<vector<char>>path(n,vector<char>(m));
     /* for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              //cout<<path[i][j]<<" ";
              path[i][j]='*';
          }
          //cout<<endl;
      }*/
      queue<pair<int,int>>pq;
      int si=-1;
      int sj=-1;
      int ei=-1;
      int ej=-1;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              if(arr[i][j]=='A')
              {
                  //count=dfs(i,j,arr,vis,n,m,s);
                  si=i;
                  sj=j;
                  //break;

                  //count++;
              }
              else if(arr[i][j]=='B')
              {
                  ei=i;
                  ej=j;
              }
          }

      }
      pq.push({si,sj});
      vis[si][sj]=1;
      bool track2=false;
      while(!pq.empty())
      {
          pair<int,int>p=pq.front();
          pq.pop();
          for(int i=0;i<4;i++)
          {
              if(p.first+dx[i]>=0 && p.first+dx[i]<n && p.second+dy[i]>=0 && p.second+dy[i]<m && vis[p.first+dx[i]][p.second+dy[i]]==0 && arr[p.first+dx[i]][p.second+dy[i]]=='.')
              {
                  pq.push({p.first+dx[i],p.second+dy[i]});
                  vis[p.first+dx[i]][p.second+dy[i]]=1;
                  path[p.first+dx[i]][p.second+dy[i]]=track[i];

              }
              else if(p.first+dx[i]>=0 && p.first+dx[i]<n && p.second+dy[i]>=0 && p.second+dy[i]<m && vis[p.first+dx[i]][p.second+dy[i]]==0 && arr[p.first+dx[i]][p.second+dy[i]]=='B')
              {
                  path[p.first+dx[i]][p.second+dy[i]]=track[i];
                  vis[p.first+dx[i]][p.second+dy[i]]=1;
                  track2=true;
                  break;
              }
          }
          if(track2==true)
          {
              break;
          }
      }
    /*  for(int i=0;i<n;i++)
      {
          for(int j=0;j<m;j++)
          {
              cout<<path[i][j]<<" ";
          }
          cout<<endl;
      }*/
      if(track2==false)
      {
          cout<<"NO"<<endl;

      }
      else{
           // string ans="";
           vector<char>ans;
      while(true)
      {
          char val=path[ei][ej];
          if(val=='D')
          {
              ei--;
              //ans=ans+'D';
              ans.push_back(val);
          }
          else if(val=='U')
          {
              ei++;
              //ans=ans+'U';
               ans.push_back(val);
          }
          else if(val=='R')
          {
              ej--;
              //ans=ans+'R';
               ans.push_back(val);
          }
          else if(val=='L')
          {
              ej++;
             // ans=ans+'L';
              ans.push_back(val);
          }
          if(ei==si && ej==sj)
          {
              break;
          }
      }
       reverse(ans.begin(),ans.end());
       cout<<"YES"<<endl;
       cout<<ans.size()<<endl;
      // cout<<ans<<endl;
      for(int i=0;i<ans.size();i++)
      {
          cout<<ans[i];
      }
      cout<<endl;

      }



    }
}
