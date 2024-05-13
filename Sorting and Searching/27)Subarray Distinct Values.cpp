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
#define all(x) x.begin(),x.end()
//Ordered Set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key

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
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    map<ll,ll>freq;
    ll distinct=0;
    ll r=0;
    ll l=0;
    ll ans=0;
    while(r<n){
        if(freq[arr[r]]==0){
            distinct++;
        }
        freq[arr[r]]++;
        while(distinct>k){
            freq[arr[l]]--;
            if(freq[arr[l]]==0)distinct--;
            l++;
        }
        ans+=(r-l)+1;//Subarray ending at r
        r++;
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