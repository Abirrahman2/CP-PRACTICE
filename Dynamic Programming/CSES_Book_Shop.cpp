#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,w;
    cin>>n>>w;
    int wt[n];
    int cost[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }
    //now we will optimize our space

    vector<int>prev(w+1,0);
    prev[0]=0;
    for(int i=1;i<=w;i++)
    {
        if(wt[n-1]<=i)
        {
            prev[i]=cost[n-1];
        }
    }

    for(int i=n-2;i>=0;i--)
    {
        vector<int>cur(w+1,0);
        for(int j=1;j<=w;j++)
        {
            int pick=0;
            int notpick=0;
            if(wt[i]<=j)
            {
                pick=cost[i]+prev[j-wt[i]];
            }
            notpick=prev[j];
            cur[j]=max(pick,notpick);
        }
        prev=cur;
    }
    cout<<prev[w]<<endl;
}

