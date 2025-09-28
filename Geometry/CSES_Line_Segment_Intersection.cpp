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
    cin>>t;
    while(t--)
    {
        P p1,p2,p3,p4;
        p1.input();
        p2.input();
        p3.input();
        p4.input();
        if((p2-p1) *(p4-p3)==0)//parallel cases...
        {

            if((p2-p1)*(p3-p1)!=0)
            {
                cout<<"NO"<<endl;//like two parallel line with no intersect point

            }
            else{//but point C can be parallel and area can be zero.
                    //like collinear line. A----B(gap)C---D, in this case its also NO.
                    //so if we want to find the gap, we can use another trick
                    //like bounding box

                if(max(p1.x,p2.x)<min(p3.x,p4.x) || max(p1.y,p2.y)<min(p3.y,p4.y) ||
                   max(p3.x,p4.x)<min(p1.x,p2.x) || max(p3.y,p4.y)<min(p1.y,p2.y))
                {
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }
            continue;
        }


        long long val1=(p2-p1)*(p3-p1);
        long long val2=(p2-p1)*(p4-p1);

        long long val3=(p4-p3)*(p1-p3);
        long long val4=(p4-p3)*(p2-p3);
        //in this problem we need to consider many cases.
        //we first check if AB is a line and CD is a line
        //we need to check is point C,D is on the left or right side with respect to Point B
        //and similarly we need to check another case
        //maybe point C,D are left and right side,
        //so now we need to check is AB on the left or right side with respect to point C.
        //so after this cases, we need to handle another case which is parallel
        //maybe AB and CD are parallel
        //so we need to check is AB and CD are collinear or not.


        if((val1<0 && val2<0) || (val1>0 && val2>0))
        {
            cout<<"NO"<<endl;
        }
        else if((val3<0 && val4<0) || (val3>0 && val4>0))
        {
            cout<<"NO"<<endl;

        }
        else{
            cout<<"YES"<<endl;
        }


    }
}

