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
/*----------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
//ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*----------------------------------------------------------------------------------------------------------------------------*/
void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>graph(n+1,vector<pair<ll,ll>>());
    map<pair<ll,ll>,ll>weight;
    for(ll i=1;i<=m;i++){
        ll x,y,c;
        cin>>x>>y>>c;
        graph[x].push_back(MP(y,c));
        weight[MP(x,y)]=c;
    }
    vector<ll>dist0(n+1,1e18);//Coupon not Used
    dist0[1]=0;
    vector<ll>dist1(n+1,1e18);//Coupon Used
    dist1[1]=0;
    priority_queue<pair<ll,pair<ll,ll>>>pq;//Distance,(Node,Coupon Used)
    pq.push(MP(0,MP(1,0)));
    while(pq.empty()==false){
        ll node=pq.top().S.F;
        ll couponUsed=pq.top().S.S;
        ll currentDistance=-pq.top().F;
        pq.pop();
        //Important Checker
        if(couponUsed==0&&dist0[node]!=currentDistance){
            continue;
        }
        if(couponUsed==1&&dist1[node]!=currentDistance){
            continue;
        }
        for(auto v:graph[node]){
            ll nxtNode=v.F;
            ll weight=v.S;
            if(couponUsed==0){
                //Use Coupon
                if(dist1[nxtNode]>dist0[node]+weight/2){
                    dist1[nxtNode]=dist0[node]+weight/2;
                    pq.push(MP(-dist1[nxtNode],MP(nxtNode,1)));
                }
                //Dont Use Coupon
                if(dist0[nxtNode]>dist0[node]+weight){
                    dist0[nxtNode]=dist0[node]+weight;
                    pq.push(MP(-dist0[nxtNode],MP(nxtNode,0)));
                }
            }
            else{
                if(dist1[nxtNode]>dist1[node]+weight){
                    dist1[nxtNode]=dist1[node]+weight;
                    pq.push(MP(-dist1[nxtNode],MP(nxtNode,1)));
                }
            }
            dist1[nxtNode]=min(dist1[nxtNode],dist0[nxtNode]);
        }
    }
    ll ans=min(dist0[n],dist1[n]);
    cout<<ans<<endl;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    //**********************************************************************
    //**********************************************************************
    ll t = 1;
    //cin>>t;
    for (ll i = 1; i <= t; i++) {
        //cout<<"Case #"<<i<<endl;
        cerr<<"Case #"<<i<<endl;
        solve();
    }
    return 0;
}