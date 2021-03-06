// Author : Pandit Deepesh Kumar Sharma ( dk30390 )
// Prerequisite : Inverse Modulo , Fermat's Little Theorem 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
#define ll long long int
ll modulo(ll a,ll b,ll p)
{   ll ret;
   if (b == 0)
      return 1;
    ret = modulo(a,b/2,p);
    ret = (ret * ret)%p;
   if ((b % 2) == 1)
       ret = (ret*a) %p;
   return (ret%p);
}
int main()
{
    ll i,j,k,l,n,m,t;

    cin>>t;
    int mark[100005],pref[100005],a[100005];
    while(t--)
    {
        cin>>n>>k>>m;
        pref[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if((a[i]^k)>m)
                mark[i]=1;
            else
                mark[i]=0;
            pref[i]=pref[i-1]+(mark[i]^1);

        }
        int ans=0;
        for(i=1;i<=n;i++)
           if(mark[i]==1)
                ans=ans+pref[n]-pref[i];
      if(ans!=0)
      cout<<modulo(ans,mod-2,mod)<<endl;
      else
      cout<<"-1"<<endl;
    }
}
