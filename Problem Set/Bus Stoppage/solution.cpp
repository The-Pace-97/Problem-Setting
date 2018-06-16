// Author : Pandit Deepesh Kumar Sharma
// Prerequisite : Segment Tree + Dynamic Programming
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[100001],n;
int jumpon[100001],getans[100001];
struct combo
{
    int idx=0;
    int jump=0;
};
combo tree[400001],temp;
void build(int start,int last,int pos)
{
   if(start==last)
   {
     tree[pos].idx=last;
     tree[pos].jump=min(last+a[last],n);
     return ;
   }
   else
   {
       int mid=(start+last)>>1;
       build(start,mid,pos<<1);
       build(mid+1,last,(pos<<1)+1);
       tree[pos]=tree[pos*2+1];
       if(tree[pos*2].jump>tree[pos*2+1].jump)
        tree[pos]=tree[pos*2];
       return ;
   }
}
combo query(int start,int last,int pos,int left,int right)
{
   if(start>right||last<left)
    return temp;
   if(start>=left&&last<=right)
    return tree[pos];
   ll mid=(start+last)>>1;
   combo first=query(start,mid,pos*2,left,right);
   combo second=query(mid+1,last,pos*2+1,left,right);
   combo ret=second;
   if(first.jump>second.jump)
    ret=first;
   return ret;

}
ll solve(int initial)
{
    if(getans[initial]!=0)
        return getans[initial];
    if(initial==n)
        return getans[initial]=0;

   return getans[initial]=solve(jumpon[initial])+1;
}
int main()
{
    int i,j,k,l,m,q,t,r;

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>a[i];
    build(1,n,1);

    for(i=1;i<=n;i++)
    {
      combo ans=query(1,n,1,i+1,min(i+a[i],n));
      jumpon[i]=ans.idx;
    }
    for(i=1;i<=n;i++)
    {
        if(getans[i]==0)
        solve(i);
    }
    cin>>q;
    while(q--)
    {
        cin>>k;
        cout<<getans[k]<<endl;
    }

}
