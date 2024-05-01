#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define intmax INT_MAX
#define intmin INT_MIN
#define PI 3.1415926535897932384626433832795
#define ed "\n"
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define endl "\n"
const long long MOD =1e9+7;
 
const ll inf = 1e15;
const ll N = 200005;
//*********************************************************************************************************
ll ans=1e18;
ll n;
ll arr[101];
void rec(ll level,ll part1,ll part2){
    if(level==n){
        ll current=abs(part2-part1);
        ans=min(ans,current);
        return;
    }
    rec(level+1,part1+arr[level],part2);
    rec(level+1,part1,part2+arr[level]);
}
void solve(){
    cin>>n;
    for(ll i=0;i<n;i++)cin>>arr[i];
    rec(0,0,0);
    cout<<ans<<endl;

}
//*********************************************************************************************************
signed int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //*********************************
    //PreProcessing
    //********************************
    ll t = 1;
    //cin >> t;
    //cout<<endl;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}
