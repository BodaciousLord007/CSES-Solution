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
    ll n,s;
    cin>>n>>s;
    vector<pair<ll,ll>>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i].F;
        arr[i].S=i+1;
    }
    sort(arr.begin(),arr.end());
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll k=j+1;
            ll l=n-1;
            ll target=s-arr[i].F-arr[j].F;
            while(k<l){
                if(arr[k].F+arr[l].F==target){
                    cout<<arr[i].S<<" "<<arr[j].S<<" "<<arr[k].S<<" "<<arr[l].S<<endl;
                    return;
                }
                else if(arr[k].F+arr[l].F<target){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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