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
    for(auto &v:arr)cout<<v<<" ";
    cout<<endl;
}
//*********************************************************************************************************
void solve(){
    ll n;
    cin>>n;
    ll sum=(n*(n+1))/2;
    if(sum%2==1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    set<ll>part1;
    set<ll>part2;
    ll left=4;
    ll right=n;
    ll turn=0;
    if(n%2==1){
        part1.insert(1);
        part1.insert(2);
        part2.insert(3);
    }
    while(left<right){
        if(turn==0){
            part1.insert(left);
            part1.insert(right);
        }
        else{
            part2.insert(left);
            part2.insert(right);
        }
        left++;
        right--;
        turn=(turn+1)%2;
    }
    cout<<(ll)part1.size()<<endl;
    for(auto v:part1){
        cout<<v<<" ";
    }
    cout<<endl;
    cout<<(ll)part2.size()<<endl;
    for(auto v:part2){
        cout<<v<<" ";
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