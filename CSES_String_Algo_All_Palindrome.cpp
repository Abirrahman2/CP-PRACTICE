#include<bits/stdc++.h>
using namespace std;
string makeOdd(string &s)
{
    string temp;
    temp.push_back('#');
    for(int i=0;i<s.size();i++)
    {
        temp.push_back(s[i]);
        temp.push_back('#');
    }
    return temp;
}
vector<int> findLongestByManacher(string &s)
{
    int track=0;//we store the position where we find the center which carry the longest palindrome.
    int maxLen=1;
    s=makeOdd(s);
    int n=s.size();
    vector<int>p(n,0);
    int l=0;
    int r=0;
    for(int i=0;i<n;i++)//each index is now center
    {
        int radius=0;
        if(i>r)
        {
            radius=0;//we need to compute from scratch.
        }
        else
        {
            int mirror=l+r-i;
            if(mirror-p[mirror]>l)
            {
                p[i]=p[mirror];
                if(maxLen<p[i])
                {
                    maxLen=p[i];
                    track=i;//we store center point
                }
                continue;//don't need to compute again, here the main optimization we make.
            }
            else
            {
                radius=r-i;//here we might get mirror-p[mirror]<=l, for that reason we will take r-i length right now, maybe in future we might get more similar char.
                //another optimization we make.
            }
        }
        while(i-radius>=0 && i+radius<n && s[i+radius]==s[i-radius])
        {
            radius++;//for any character we will increase this by one for character itself.
            //so will decrease this after execution.
        }
        radius--;
        p[i]=radius;
        if(maxLen<p[i])
        {
            track=i;
            maxLen=p[i];
        }
        if(i+radius>r)//that means our new palindrome boundary is now changed.
        {
            l=i-radius;
            r=i+radius;
        }
    }
    //cout<<track<<endl;

   return p;
}
int main()
{
    string s;
    cin>>s;
    int nn=s.size();
    vector<int> track=findLongestByManacher(s);
    int n=track.size();
    vector<int>ans(nn,0);
    for(int i=1;i<n;i++)
    {
        int temp=track[i];
        int real=i/2;
        if(i%2==0)
        {
            real--;

        }
         temp=temp/2;
         ans[real+temp]=max(ans[real+temp],track[i]);

    }
    int maxi=ans[nn-1];
    for(int i=nn-2;i>=0;i--)
    {
        if(ans[i]<maxi-2)
        {
            ans[i]=maxi-2;
            maxi=maxi-2;
        }
        else{
            maxi=ans[i];
        }

    }
    for(int i=0;i<nn;i++)
    {

        cout<<ans[i]<<" ";

    }

    //cout<<ans<<endl;
    //cout<<ans.size()<<endl;
}

