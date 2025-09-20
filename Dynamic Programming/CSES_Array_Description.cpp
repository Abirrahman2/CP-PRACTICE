#include<bits/stdc++.h>
using namespace std;
const int mod=1e9 +7;
/*int fun(int ind,int prev,int m,int arr[])
{

    if(ind==0)
    {
        if(arr[ind]==0)return 1;

        if(abs(arr[ind]-prev)>1) return 0;
        else return 1;
    }

    int ans=0;
    if(prev==-1 && arr[ind]!=0)
    {
        if(arr[ind]!=0)
        {
            for(int i=arr[ind]-1;i<=arr[ind]+1;i++)
            {
                if(i>=1 && i<=m)
                {
                    if(arr[ind]!=0 && arr[ind]!=i)continue;
                    ans=ans+fun(ind-1,i,m,arr);
                }
            }


        }
    }
    else
    {
    for(int i=prev-1;i<=prev+1;i++)
    {
        if(i>=1 && i<=m)
        {
            if(arr[ind]!=0 && arr[ind]!=i ) continue;
            ans=ans+fun(ind-1,i,m,arr);
        }
    }

    }

    return ans;
}*/
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>>dp(n,vector<int>(m+1,0));
    if(arr[0]==0)
    {
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=1;
        }
    }
    else
    {
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {

            for(int prev=j-1;prev<=j+1;prev++)
            {
                if(prev>=1 && prev<=m)
                {
                    if(arr[i]!=0 && arr[i]!=prev)continue;
                    dp[i][prev]=((dp[i][prev]%mod)+(dp[i-1][j]%mod)%mod)%mod;
                }
            }

        }
    }
  /*  for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        ans=(ans+dp[n-1][i])%mod;
    }
    cout<<ans<<endl;
}

