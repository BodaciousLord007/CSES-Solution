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
void print(vector<ll>&arr){
    for(auto &v:arr)cout<<v<<" ";
    cout<<endl;
}
//*********************************************************************************************************
void solve(){
    ll n;
    cin>>n;
    ll current=n;
    ll cnt5=0;
    while(current/5>0){
        cnt5=cnt5+current/5;
        current=current/5;
    }
    current=n;
    ll cnt2=0;
    while(current/2>0){
        cnt2=cnt2+current/2;
        current=current/2;
    }
    ll ans=min(cnt5,cnt2);
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