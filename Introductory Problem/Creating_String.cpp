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
void print(vector<ll>&arr){
  for(auto &v:arr){
    cout<<v<<" ";
  }
  cout<<endl;
}
 
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// 1)MOD Addition
inline ll modadd(ll a, ll b, ll mod = MOD)
{
    return (a % mod + b % mod + 2 * mod) % mod;
}
// 2)MOD Subtraction
inline ll modsub(ll a, ll b, ll mod = MOD)
{
    return (a % mod - b % mod + 2 * mod) % mod;
}
// 3)MOD Multiplication
inline ll modmul(ll a, ll b, ll mod = MOD)
{
    return ((a % mod) * (b % mod)) % mod;
}
// 4)MOD Exponentiation
ll binexp(ll a, ll b, ll mod = MOD)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ((ans % mod) * (a % mod)) % mod;
        }
        a = ((a % mod) * (a % mod)) % mod;
        b = b / 2;
    }
    return ans;
}
// 5)MOD Inverse
inline ll modinv(ll a, ll mod = MOD)
{
    return binexp(a, mod - 2);
}
void printst(set<int> st){
    for(auto v:st){
        cout<<v<<" ";
    }
    cout<<endl;
}
//*********************************************************************************************************
void solve(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    ll ans=1;
    vector<string>final;
    do{
        final.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<final.size()<<endl;
    for(auto v:final){
        cout<<v<<endl;
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