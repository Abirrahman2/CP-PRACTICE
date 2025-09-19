#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        vector<int>prev(k+1,0);
         prev[0]=1;
        for(int i=1;i<=k;i++)
        {
            if(i%arr[0]==0)
            {
                prev[i]=1;
            }
        }
      //space optimization
        for(int i=1;i<n;i++)
        {
            vector<int>cur(k+1,0);
            cur[0]=1;
            for(int sum=1;sum<=k;sum++)
            {
                int pick=0;
                int notpick=0;
                if(sum-arr[i]>=0)
                {
                    pick=(cur[sum-arr[i]])%mod;
                }

                 notpick=prev[sum]%mod;


                cur[sum]=(pick+notpick)%mod;
            }
            prev=cur;
        }
//        for(int i=0;i<n;i++)
//        {
//            for(int sum=0;sum<=k;sum++)
//            {
//                cout<<dp[i][sum]<<" ";
//            }
//            cout<<endl;
//        }
        cout<<prev[k]<<endl;
    }
}

