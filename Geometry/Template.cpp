#include<bits/stdc++.h>
using namespace std;
struct P{

    long long x,y;
    void input()
    {
        cin>>x>>y;
    }

    P operator -(const P& a)
    {

        return P{x-a.x,y-a.y};
    }

    void operator -=(const P& a)
    {
        x-=a.x;
        y-=a.y;
    }




};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        P p1,p2,p3;

        p1.input();
        p2.input();
        p3.input();
        //we can do the below things,
        //previously it was done by x2-x1, y2-y1;
        p2=p2-p1;
        p3=p3-p1;
        //we can also do the same things
        p2-=p1;
        p3-=p1;
        cout<<p2.x<<" "<<p2.y<<endl;
    }
}

