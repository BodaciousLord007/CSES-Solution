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
