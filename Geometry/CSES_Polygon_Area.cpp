#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<long long>>v;
        for(int i=0;i<n;i++)
        {
            long long x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        long long ans=0;
        for(int i=0;i<n-1;i++)
        {
            ans=ans+((v[i][0]*v[i+1][1])-(v[i+1][0]*v[i][1]));

        }
        ans=ans+((v[n-1][0]*v[0][1])-(v[0][0]*v[n-1][1]));
        cout<<abs(ans)<<endl;
    }
}

