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
    ll x,p;
    cin>>x>>p;
    set<ll>pole;
    pole.insert(0);
    pole.insert(x);
    multiset<ll>gap;
    ll best=0;
    ll l=0;
    ll r=x;
    gap.insert(x);
    for(ll i=0;i<p;i++){
        ll newpos;
        cin>>newpos;
        //1)Finding left and right position and inserting new pole
        auto it=pole.lower_bound(newpos);
        ll right=*(it);
        ll left=0;
        ll ans=(*it)-newpos;
        if(it!=pole.begin()){
            it--;
            left=(*it);
        }
        pole.insert(newpos);
        //2)Removing old gap and inserting new gap       
        gap.erase(gap.find(right-left));
        gap.insert(newpos-left);
        gap.insert(right-newpos);
        cout<<*(gap.rbegin())<<endl;    
    }
    cout<<endl;
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