#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>lps(n,0);
    int i=1;
    int len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
    vector<int>ans;
    int j=n;
    while(j>0)
    {
        ans.push_back(n-lps[j-1]);
        j=lps[j-1];


    }
    //ans.push_back(n);
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}

