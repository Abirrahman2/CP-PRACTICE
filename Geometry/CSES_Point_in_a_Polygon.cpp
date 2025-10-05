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
bool intersection(P p1,P p2,P p3, P p4)
{
        if((p2-p1) *(p4-p3)==0)//parallel cases...
        {

            if((p2-p1)*(p3-p1)!=0)
            {
                //cout<<"NO"<<endl;//like two parallel line with no intersect point
                return false;

            }
            else{//but point C can be parallel and area can be zero.
                    //like collinear line. A----B(gap)C---D, in this case its also NO.
                    //so if we want to find the gap, we can use another trick
                    //like bounding box

                if(max(p1.x,p2.x)<min(p3.x,p4.x) || max(p1.y,p2.y)<min(p3.y,p4.y) ||
                   max(p3.x,p4.x)<min(p1.x,p2.x) || max(p3.y,p4.y)<min(p1.y,p2.y))
                {
                    //cout<<"NO"<<endl;
                    return false;
                }
                else{

                    //cout<<"YES"<<endl;
                    return true;
                }
            }

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
            //cout<<"NO"<<endl;
            return false;
        }
        else if((val3<0 && val4<0) || (val3>0 && val4>0))
        {
            //cout<<"NO"<<endl;
            return false;

        }
        else{
           // cout<<"YES"<<endl;
           return true;
        }

        return false;
}
bool checkBoundary(P a,P b,P c)//this will check is c is on boundary or not
{
    //lets assume ac is a line and cb is a line
    //now just simply check is this two is collinear or not if yes then is it in
    //same boundary or not using bounding box.
    if((b-a)*(c-a)!=0)return false;//not collinear
//    if(c.y==a.y && b.y==c.y)
//    {
//        if(a.x<b.x)
//        {
//            if(c.x<a.x)return false;
//            else return true;
//        }
//        else{
//            if(c.x<b.x)return false;
//            else return true;
//        }
//    }
//    if(c.x==a.x && c.x==b.x)
//    {
//        if(a.y<b.y)
//        {
//            if(c.y<a.y)return false;
//            else return true;
//        }
//        else{
//            if(c.y<b.y)return false;
//            else return true;
//        }
//
//    }

    if((min(a.x,b.x)<=c.x && c.x<=max(a.x,b.x))
       && (min(a.y,b.y)<=c.y && c.y<=max(a.y,b.y)
       ))
       {
           return true;
       }
       else{
        return false;
       }

}
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<P>points(n);
        for(int i=0;i<n;i++)
        {

            points[i].input();
        }

        //now for each point i need to investigate how many intersection we have
        //how?
        //we will assume we have infinite length ray .
        //this is special ray, lets say we have point (x,y). so we need to tell is this
        //point inside or outside, just simply we will dray a vertical line with an infinite points.
        //but exactly vertical line might get collinear with other segment.
        //so we will take a point (x+1, INF). this will handle this case.

        for(int k=0;k<m;k++)
        {
            P p;
            p.input();
            P inf=P{p.x+1,3000000001*1LL};
            int count=0;
            bool track=false;
            for(int i=0;i<n;i++)
            {

                if(i+1<n)
                {
                    if(checkBoundary(points[i],points[i+1],p))
                    {
                       // cout<<points[i].x<<" "<<points[i].y<<endl;
                       // cout<<points[i+1].x<<" "<<points[i+1].y<<endl;
                        track=true;
                        break;
                    }
                    if(intersection(p,inf,points[i],points[i+1]))
                    {
                        count++;
                    }

                }
                else{
                    if(checkBoundary(points[0],points[i],p))
                    {
                        //cout<<"HELLO"<<endl;
                        track=true;
                        break;
                    }
                    if(intersection(p,inf,points[i],points[0]))
                    {
                        count++;
                    }
                }

            }
            if(track)
            {
                cout<<"BOUNDARY"<<endl;
                continue;
            }
            if(count%2==0)
            {

                cout<<"OUTSIDE"<<endl;



            }
            else{


                cout<<"INSIDE"<<endl;


            }
        }

    }
}

