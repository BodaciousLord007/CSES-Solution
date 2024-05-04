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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    vector<ll>apart(m);
    for(ll i=0;i<m;i++){
        cin>>apart[i];
    }
    sort(apart.begin(),apart.end());
    ll i=0;
    ll j=0;
    while(i<n&&j<m){
        //Valid Apartment
        if(abs(arr[i]-apart[j])<=k){
            ans++;
            i++;
            j++;
        }
        //Too Small
        else if(arr[i]>apart[j]){
            j++;
        }
        //Too Big
        else{
            i++;
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
    //cout<<endl;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}
