#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
string track="URDL";
bool isvalid(int i,int j,int n,int m)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        return true;
    }
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>adj(n,vector<char>(m));
    queue<pair<int,int>>pq;
    vector<vector<int>>levelM(n,vector<int>(m,0));

    int si;
    int sj;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>adj[i][j];
            if(adj[i][j]=='M')
            {
                pq.push({i,j});
                levelM[i][j]=0;
            }
            if(adj[i][j]=='A')
            {
                si=i;
                sj=j;
            }
        }
    }

    while(!pq.empty())
    {
        pair<int,int>p=pq.front();
        pq.pop();
        for(int i=0;i<4;i++)
        {
            if(isvalid(p.first+dx[i],p.second+dy[i],n,m)==true && levelM[p.first+dx[i]][p.second+dy[i]]==0 && adj[p.first+dx[i]][p.second+dy[i]]!='#' && adj[p.first+dx[i]][p.second+dy[i]]!='M')
            {
                levelM[p.first+dx[i]][p.second+dy[i]]=1+levelM[p.first][p.second];
                pq.push({p.first+dx[i],p.second+dy[i]});
            }
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<levelM[i][j];
//        }
//        cout<<endl;
//    }
    vector<vector<int>>levelA(n,vector<int>(m,0));
    vector<vector<char>>path(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>pq1;
    pq1.push({si,sj});
    bool track2=false;
    int ei;
    int ej;
    vis[si][sj]=1;
    if(si==n-1 || sj==m-1 || si==0 || sj==0)
    {
        ei=si;
        ej=sj;
        track2=true;
    }
    while(!pq1.empty())
    {
        pair<int,int>p=pq1.front();
        pq1.pop();

        for(int i=0;i<4;i++)
        {
            int newi=p.first+dx[i];
            int newj=p.second+dy[i];
            if(isvalid(newi,newj,n,m)==true && vis[newi][newj]==0)
            {
                if(levelA[p.first][p.second]+1<levelM[newi][newj] || (levelM[newi][newj]==0 && adj[newi][newj]=='.'))
                {
                if(newi==0 || newi==n-1 || newj==m-1 || newj==0)
                {
                    path[newi][newj]=track[i];
                    track2=true;
                    ei=newi;
                    ej=newj;
                    levelA[newi][newj]=1+levelA[p.first][p.second];
                    break;
                }
                else{
                    path[newi][newj]=track[i];
                    levelA[newi][newj]=1+levelA[p.first][p.second];
                    vis[newi][newj]=1;
                    pq1.push({newi,newj});
                }

                }

            }
        }
        if(track2==true)
        {
            break;
        }
    }
    if(track2==false)
    {
        cout<<"NO"<<endl;
    }
    else{
        vector<char>ans;
        while(true)
        {

            if(path[ei][ej]=='R')
            {
               // ans.push_back(path[ei][ej]);
               ans.push_back(path[ei][ej]);
                ej--;

            }
            else if(path[ei][ej]=='L')
            {
                ans.push_back(path[ei][ej]);
                ej++;

            }
            else if(path[ei][ej]=='U')
            {
                ans.push_back(path[ei][ej]);
                ei++;
            }
            else if(path[ei][ej]=='D')
            {
                ans.push_back(path[ei][ej]);
                ei--;
            }
            if(ei==si && ej==sj)
            {
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it;
        }
        cout<<endl;
    }
    //cout<<ei<<" "<<ej<<endl;
//for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<m;j++)
//        {
//            cout<<path[i][j];
//        }
//        cout<<endl;
//    }

}

