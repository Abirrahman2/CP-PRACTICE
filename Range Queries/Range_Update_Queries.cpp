#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class SGTree {
public:
    vector<ll> seg;
	vector<ll>lazy;
    SGTree()
    {

    }
	SGTree(int n) {

		seg.resize(4 * n + 1);
		lazy.resize(4*n+1);
	}
	void build(int ind,int low ,int high,int arr[])
	{
	    if(low==high)
        {
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	}

	ll query1(int ind,int low,int high,int pos)
	{
        if(lazy[ind]!=0)     //0       //0
        {
            seg[ind]=seg[ind]+(high-low+1)*lazy[ind];
            if(low!=high)
            {
                lazy[2*ind+1]=lazy[2*ind+1]+lazy[ind];
                lazy[2*ind+2]=lazy[2*ind+2]+lazy[ind];

            }
             lazy[ind]=0;

        }
	    if(low==high)
        {
            seg[ind]=seg[ind]+lazy[ind];
            lazy[ind]=0;
            return seg[ind];
        }
        int mid=(low+high)/2;
        ll left=0;
        ll right=0;
        if(pos<=mid)
        {
            seg[ind]=seg[ind]+(high-low+1)*lazy[ind];
            lazy[ind]=0;
            if(low!=high)
            {
              lazy[2*ind+1]=lazy[2*ind+1]+lazy[ind];
            }

            left=query1(2*ind+1,low,mid,pos);
        }
        else{
            seg[ind]=seg[ind]+(high-low+1)*lazy[ind];
            lazy[ind]=0;
            if(low!=high)
            {
                lazy[2*ind+2]=lazy[2*ind+2]+lazy[ind];
            }

            right=query1(2*ind+2,mid+1,high,pos);
        }
        return left+right;
	}
	void update(int ind, int low, int high, int i,int j,int val) {
	    if(lazy[ind]!=0)     //0       //0
        {
            seg[ind]=seg[ind]+(high-low+1)*lazy[ind];
            if(low!=high)
            {
                lazy[2*ind+1]=lazy[2*ind+1]+lazy[ind];
                lazy[2*ind+2]=lazy[2*ind+2]+lazy[ind];

            }
             lazy[ind]=0;

        }
        if(high<i || low>j)
        {
            return;
        }
        if(low>=i && high<=j)
        {
            seg[ind]=seg[ind]+(high-low+1)*val;
            if(low!=high)
            {
               lazy[2*ind+1]=lazy[2*ind+1]+val;
               lazy[2*ind+2]=lazy[2*ind+2]+val;
            }
           return;
        }
		int mid=(low+high)/2;
		update(2*ind+1,low,mid,i,j,val);//left
		update(2*ind+2,mid+1,high,i,j,val);//right->1 -1
		seg[ind]=seg[2*ind+1]+seg[2*ind+2];

	}
	void print()
	{
	    for(auto it:seg)
        {
            cout<<it<<" ";
        }
	}


};
int main()
{

    int n,m;
    cin>>n>>m;
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    SGTree sg1(n);
    sg1.build(0,0,n-1,arr1);
   // sg1.print();
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int l,r,v;
            cin>>l>>r>>v;
          sg1.update(0,0,n-1,l-1,r-1,v);
        }
        else{
            int pos;
            cin>>pos;
            pos--;
            cout<<sg1.query1(0,0,n-1,pos)<<endl;
        }
    }

}
