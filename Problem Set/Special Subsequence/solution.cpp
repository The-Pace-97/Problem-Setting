// Author         : Pandit Deepesh Kumar Sharma  ( dk30390 )
// Prerequisite   : Understanding of Prime Factorisation 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ll i,ans,n,t;
    cin>>t;
    string str;
    int frequency[150];
    while(t--)
    {
        cin>>n>>str;
        for(i=1;i<=149;i++)
            frequency[i]=0;
        for(i=0;i<str.size();i++)
        {
            frequency[str[i]]++;
        }
        ans=1;
        for(i='a';i<='z';i++)
         if(frequency[i]!=0)
         {
            ans=(ans*(frequency[i]+1))%mod;
         }
        cout<<(ans-1+mod)%mod<<endl;
    }
}
