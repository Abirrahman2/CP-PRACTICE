#include<bits/stdc++.h>
using namespace std;
vector<int> digit(int n)
{
    int count=0;
    vector<int>ans;
    while(n!=0)
    {
        ans.push_back(n%10);
        n=n/10;
        count++;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int ways(int n,vector<int>&dp)
{
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    vector<int>digits=digit(n);
    int mini=INT_MAX;
    for(int i=0;i<digits.size();i++)
    {
        if(digits[i]==0)continue;
        mini=min(mini,1+ways(n-digits[i],dp));
    }
    //cout<<mini<<endl;
    return dp[n]=mini;
}
int main()
{
    int n;
    cin>>n;
    vector<int>digits=digit(n);
    vector<int>dp(n+1,1e9);
    //tabulation
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        vector<int>digits=digit(i);
        int mini=INT_MAX;
        for(int j=0;j<digits.size();j++)
        {
              if(digits[j]==0)continue;
              mini=min(mini,1+dp[i-digits[j]]);
        }
        dp[i]=mini;
    }
//    for(auto it:digits)
//    {
//        cout<<it<<" ";
//    }
    cout<<dp[n]<<endl;

}

