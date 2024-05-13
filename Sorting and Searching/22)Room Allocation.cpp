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
void printld(vector<ld>arr){
    for(auto v:arr)cout<<v<<" ";
    cout<<endl;
}
void solve(){
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].F.F>>arr[i].F.S;
        arr[i].S=i;
    }
    sort(arr.begin(),arr.end());
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;//Checkout,RoomNo
    ll ans=0;
    vector<ll>final(n);
    for(ll i=0;i<n;i++){
        if(pq.empty()){
            ans++;
            pq.push(MP(arr[i].F.S,ans));
            final[arr[i].S]=ans;
        }
        else if(pq.top().F>=arr[i].F.F){
            ans++;
            pq.push(MP(arr[i].F.S,ans));
            final[arr[i].S]=ans;
        }
        else{
            final[arr[i].S]=pq.top().S;
            pq.pop();
            pq.push(MP(arr[i].F.S,final[arr[i].S]));
        }
    }
    cout<<ans<<endl;
    for(auto v:final)cout<<v<<" ";
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