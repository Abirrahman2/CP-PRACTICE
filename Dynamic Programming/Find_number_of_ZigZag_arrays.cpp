#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>>dp(2000,vector<vector<int>>(2000,vector<int>(2,0)));
class Solution {
public:
const int mod=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<2;j++)
            {
               dp[0][i][j]=1;
            }
        }
      //we need to understand the transition.
      //dp[i][x][0] means i need to feel the dp with length i with value x when my previous value
      // was less then me. so dp[i][x][0]=sum of(dp[i-1][y<x][1])
      //here 0 signify, we are at increasing position,so we need to look at decreasing state
      //here 1 signify , we are currently at decreasing position, so we need to look at how many
      //values are there which are coming to me and those values are greater than me.
      //dp[i][x][1]=sum of(dp[i-1][y>x][0])..why 0? because we need to look at increasing state
      //to fill this current decreasing state.
        for(int i=1;i<n;i++)
        {
            int prefix=0;
            for(int j=0;j<m;j++)
            {
                dp[i][j][0]=prefix;
                prefix=(prefix+dp[i-1][j][1])%mod;
            }
            int suffix=0;

            for(int j=m-1;j>=0;j--)
            {
                dp[i][j][1]=suffix;
                suffix=(suffix+dp[i-1][j][0])%mod;
            }
        }

        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum=(sum+dp[n-1][i][0])%mod;
            sum=(sum+dp[n-1][i][1])%mod;
        }
        return sum;
    }
};
int main()
{

}
