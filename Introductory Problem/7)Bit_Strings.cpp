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
//MOD Exponentiation
ll binexp(ll a, ll b, ll mod = MOD)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ((ans % mod) * (a % mod)) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b = b / 2;
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    cout<<binexp(2,n)<<endl;
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