#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string pattern;
    cin>>pattern;
    //first find LPS
    int lps[pattern.size()]={0};
    int i=1;
    int len=0;
    while(i<pattern.size())
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;//we matched something.
            i++;
        }
        else{              //if not matched
                           //we have two options
                           //maybe we end up in index 0
                           //so then we will increase the i.

                if(len==0)
                {
                   lps[i]=0;
                   i++;

                }
                else
                {
                    len=lps[len-1];//this part is the main trick.
                }

        }
    }
    //now kmp algorithm
    i=0;
    int j=0;
    int ans=0;
    while(i<s.size())
    {
        if(s[i]==pattern[j])
        {
            i++;
            j++;
        }
        else{
            if(j==0)
            {
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
        if(j==pattern.size())
        {
            ans++;
            j=lps[j-1];
        }
    }
    cout<<ans<<endl;
}

