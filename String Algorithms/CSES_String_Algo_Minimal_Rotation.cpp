#include<bits/stdc++.h>
using namespace std;
string findMinimum(string s)
{

    s=s+s;
    int n=s.size();
    int ans=0;
    int i=0;
    while(i<n/2)
    {
        int j=i+1;
        int k=i;
        ans=i;
        while(j<n && s[k]<=s[j])
        {
            if(s[k]==s[j])
            {
                k++;
            }
            else{
                k=i;
            }
            j++;
        }
        while(i<=k)
        {
            i=i+j-k;
        }
    }
    return s.substr(ans,n/2);
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    cout<<findMinimum(s)<<endl;
}

