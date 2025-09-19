#include<bits/stdc++.h>
using namespace std;
int main()
{
   string pattern;
   cin>>pattern;
   int i=1;
   int len=0;
   int lps[pattern.size()]={0};
   while(i<pattern.size())
   {
       if(pattern[i]==pattern[len])
       {
           len++;
           lps[i]=len;
           i++;

       }
       else
       {

           if(len==0)
           {
               lps[i]=0;
               i++;
           }
           else
           {
               len=lps[len-1];
           }
       }
   }


   int j=pattern.size()-1;
   vector<int>ans;
   while(j>0)
   {
       if(lps[j]!=0)
       {
           ans.push_back(lps[j]);
       }
       else
       {
           break;
       }

       j=lps[j]-1;
   }
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}


