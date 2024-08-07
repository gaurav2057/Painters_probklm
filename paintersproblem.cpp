#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int arr[100005];
int check(int x)
{
   int lastleft=0;
   int needed=0;
   for(int i=0;i<n;i++)
   {
    if(lastleft>=arr[i])
    {
        lastleft-=arr[i];
    }
    else {
        needed++;
        lastleft=x-arr[i];
    }
    if(needed>k) return 0;
   }
   if(needed>k) return 0;
   else return 1;
}
void sol(){
    cin>>n>>k;
    int lo=0,hi=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        lo=max(lo,arr[i]);
        hi+=arr[i];
    }
    int ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid))
        {
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}