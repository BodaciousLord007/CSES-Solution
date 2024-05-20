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
    string s;
    cin>>s;
    ll n=(ll)s.length();
    vector<ll>cnt(26,0);
    for(ll i=0;i<n;i++){
        cnt[s[i]-'A']++;
    }
    ll odd=0;
    ll oddindex;
    for(ll i=0;i<26;i++){
        if(cnt[i]%2==1){
            odd++;
            oddindex=i;
        }
    }
    if(odd>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    for(ll i=0;i<26;i++){
        char current='A'+i;
        if(cnt[i]%2==1)continue;
        for(ll j=0;j<cnt[i]/2;j++){
            cout<<current;
        }
    }
    if(odd==1){
        char oddchar='A'+oddindex;
        for(int i=0;i<cnt[oddindex];i++){
            cout<<oddchar;
        }
    }
    for(ll i=25;i>=0;i--){
        char current='A'+i;
        if(cnt[i]%2==1)continue;
        for(ll j=0;j<cnt[i]/2;j++){
            cout<<current;
        }
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
    //cout<<endl;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}
