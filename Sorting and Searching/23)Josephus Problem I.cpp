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
void printld(vector<ld>arr){
    for(auto v:arr)cout<<v<<" ";
    cout<<endl;
}
void solve(){
    ll n;
    cin>>n;
    vector<ll>remaining;
    for(ll i=0;i<n;i++){
        remaining.push_back(i+1);
    }
    while(remaining.empty()==false){
        vector<ll>temp;
        if(remaining.size()==1){
            cout<<remaining[0]<<endl;
            break;
        }
        for(ll i=0;i<remaining.size();i++){
            if(i%2==0){
                temp.push_back(remaining[i]);
            }
            else{
                cout<<remaining[i]<<" ";
            }
        }
        if(remaining.size()%2==1){
            ll elm=temp.back();
            temp.pop_back();
            reverse(temp.begin(),temp.end());
            temp.push_back(elm);
            reverse(temp.begin(),temp.end());
        }
        remaining=temp;
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