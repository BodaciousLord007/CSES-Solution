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
#define all(x) (x).begin(), (x).end()
//***********************************************************************************
void solve(){
    ll n;
    cin>>n;
    //cout<<"Target->"<<n<<endl;
    ll lastlimit=0;
    ll nxt=9;
    ll digit=0;
    ll base=0;
    while(lastlimit+nxt*(digit+1)<n){
        lastlimit=lastlimit+nxt*(digit+1);
        digit++;
        nxt=nxt*10;
        base=base*10+9;
    }
    digit++;
    //cout<<"Base->"<<base<<",LastLimit->"<<lastlimit<<",digit->"<<digit<<endl;
    ll left=n-lastlimit;
    ll num=base+(left)/digit+(left%digit!=0);
    ll deletionrequired=left%digit;
    if(deletionrequired!=0){
        deletionrequired=digit-deletionrequired;
    }
    //cout<<"Number->"<<num<<",DeletionRequired->"<<deletionrequired<<endl;
    while(deletionrequired--){
        num=num/10;
    }
    cout<<num%10<<endl;
}
//************************************************************************************
signed int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //*********************************
    //PreProcessing
    //********************************
    ll t = 1;
    cin >> t;
    //cout<<endl;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}