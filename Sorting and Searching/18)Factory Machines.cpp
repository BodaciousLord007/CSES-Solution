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
ll mod=MOD;
const ll inf = 1e15;
const ll N = 200005;
//*********************************************************************************************************
void print(vector<ll>arr){
    for(auto v:arr)cout<<v<<" ";
    cout<<endl;
}
ll n,target;
ll speed[200001];
bool check(ll time){
    ll product=0;
    for(ll i=0;i<n;i++){
        product=product+(time/speed[i]);
    }
    return product>=target;
}
void solve(){
    cin>>n>>target;
    for(ll i=0;i<n;i++)cin>>speed[i];
    sort(speed,speed+n);
    ll lo=0;
    ll hi=speed[0]*target;//For avoiding to go to out of range
    ll ans=1e18;
    while(lo<=hi){
        ll mid=lo+(hi-lo)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
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
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}