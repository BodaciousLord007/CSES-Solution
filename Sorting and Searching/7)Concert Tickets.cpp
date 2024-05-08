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
void solve(){
    ll n,m;
    cin>>n>>m;
    multiset<ll>ticket;
    for(ll i=0;i<n;i++){
        ll val;
        cin>>val;
        ticket.insert(val);
    }
    for(ll i=0;i<m;i++){
        ll maxprice;
        cin>>maxprice;
        auto it=ticket.upper_bound(maxprice);
        if(it!=ticket.begin()){
            it--;
            cout<<*(it)<<endl;
            ticket.erase(it);
        }
        else{
            cout<<-1<<endl;
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
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}