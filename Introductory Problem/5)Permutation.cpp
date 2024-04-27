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
void solve(){
    ll n;
    ll odd;
    ll even;
    cin>>n;
    if(n==1){
        cout<<1;
    }
    if(n<4){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        for(even=2;even<=n;even=even+2){
            cout<<even<<" ";
        }
        for(odd=1;odd<=n;odd=odd+2){
            cout<<odd<<" ";
        }
    }
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