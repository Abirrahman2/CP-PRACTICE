#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;

        x1=x1-x;
        y1=y1-y;
        x2=x2-x;
        y2=y2-y;

        long long val=(x1*y2)-(x2*y1);
        if(val<0)
        {
            cout<<"RIGHT"<<endl;
        }
        else if(val>0)
        {
            cout<<"LEFT"<<endl;
        }
        else
        {
            cout<<"TOUCH"<<endl;
        }
    }
}

