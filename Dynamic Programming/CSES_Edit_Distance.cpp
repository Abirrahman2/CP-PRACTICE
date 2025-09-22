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
       vector<vector<int>>dp(n,vector<int>(m,-1));
       cout<<fun(n-1,m-1,s,p,dp)<<endl;
    }
}

