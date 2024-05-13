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
typedef tree<ll, null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>pbds; // find_by_order, order_of_key
 
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
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll lowersum=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(all(arr));
    for(ll i=0;i+1<n;i++){
        lowersum+=arr[i];
    }
    if(lowersum>arr[n-1]){
        cout<<lowersum+arr[n-1]<<endl;
    }
    else{
        cout<<2*arr[n-1]<<endl;
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