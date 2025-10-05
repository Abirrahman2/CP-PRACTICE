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
    long long operator *(const P& a)
    {
        return x*a.y-y*a.x;
    }
    P operator +(const P& a)
    {

        return P{x+a.x,y+a.y};
    }


};
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;

        vector<P>points(n);
        for(int i=0;i<n;i++)
        {
            points[i].input();
        }

        long long area=0;
        for(int i=0;i<n;i++)
        {
            area=area+(points[i]*points[(i+1)%n]);
        }
        //now we will use picks theorem.
        //so first we will try to find the lattice points in boundary
        //its just simple gcd, because the total number of moves to reach the point B from A,
        //is basically each time we make move (+-x,+-y)
        long long boundary=0;
        for(int i=0;i<n;i++)
        {
            P dif=points[i]-points[(i+1)%n];
            long long gcd=__gcd(abs(dif.x),abs(dif.y));
            boundary=boundary+gcd;
        }

        long long inside=(abs(area)/2-(boundary/2)+1LL);
        cout<<inside<<" "<<boundary<<endl;




    }
}

