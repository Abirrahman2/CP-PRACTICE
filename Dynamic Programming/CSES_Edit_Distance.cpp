#include<bits/stdc++.h>
using namespace std;
int fun(int i,int j,string &s,string &p,vector<vector<int>>&dp)
{
    if(i<0)return j+1;
    if(j<0)return i+1;

    if(dp[i][j]!=-1)return dp[i][j];
    int mini=0;
    int mini1=0;
    if(s[i]==p[j])
    {
       mini=0+fun(i-1,j-1,s,p,dp);
    }
    else
    {

        int add=1+fun(i,j-1,s,p,dp);
        int rep=1+fun(i-1,j-1,s,p,dp);
        int del=1+fun(i-1,j,s,p,dp);
        mini1=min(add,min(rep,del));
    }
   return dp[i][j]=mini+mini1;
}
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
       string s,p;
       cin>>s;
       cin>>p;
       int n=s.size();
       int m=p.size();
       //space optimization
       //vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       vector<int>prev(m+1,0);
       //base case
     /*  for(int i=0;i<=n;i++)
       {
           dp[i][0]=i;
       }*/
       for(int j=0;j<=m;j++)
       {
           prev[j]=j;
       }
       vector<int>cur(m+1,0);
       for(int i=1;i<=n;i++)
       {
           cur[0]=i;
           for(int j=1;j<=m;j++)
           {
               int mini=0;
               if(s[i-1]==p[j-1])
                {
                  mini=0+prev[j-1];
                }
               else
               {

                int add=1+cur[j-1];
                int rep=1+prev[j-1];
                int del=1+prev[j];
                 mini=min(add,min(rep,del));
                }
                cur[j]=mini;

           }
           prev=cur;
       }
       cout<<prev[m]<<endl;
    }
}

