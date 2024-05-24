#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//*****************************************************************************************************************************
bool cmp(pair<pair<ll,ll>,ll>a,pair<pair<ll,ll>,ll>b){
  ll l1=a.F.F;
  ll r1=a.F.S;
  ll l2=b.F.F;
  ll r2=b.F.S;
  if(l1>l2)return false;
  if(l1<l2)return true;
  if(r1>r2)return true;
  if(r1<r2)return false;
  return true;
}
void solve(){
  ll n;
  cin>>n;
  vector<pair<pair<ll,ll>,ll>>arr(n);
  for(ll i=0;i<n;i++){
    ll l,r;
    cin>>l>>r;
    arr[i].F=MP(l,r);
    arr[i].S=i;
  }
  sort(all(arr),cmp);//Left smaller->Right Bigger
  //A)Container:Checking if the current range contain any other range
  vector<ll>container(n,0);
  ll lowestend=1e18;
  for(ll i=n-1;i>=0;i--){
    if(arr[i].F.S>=lowestend){
      container[arr[i].S]=1;
    }
    lowestend=min(lowestend,arr[i].F.S);
  }
  //B)Contain:If the range is inside any other range
  vector<ll>contain(n,0);
  ll highestend=0;
  for(ll i=0;i<n;i++){
    if(arr[i].F.S<=highestend){
      contain[arr[i].S]=1;
    }
    highestend=max(highestend,arr[i].F.S);
  }
  for(auto v:container)cout<<v<<" ";
  cout<<endl;
  for(auto v:contain)cout<<v<<" ";
  cout<<endl;
}
//*****************************************************************************************************************************
int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    //*************************************************************************************************************************
    //*************************************************************************************************************************
    ll t=1;
    //cin>>t;
    for(ll i=1;i<=t;i++){
        //cout<<"Test Case #"<<i<<endl;
        solve();
    }
    return 0;
}