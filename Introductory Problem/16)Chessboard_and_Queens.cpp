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
ll n;
ll ans=0;
char chess[9][9];
ll colposition[9];
bool valid(ll row,ll col){
    //Obstruction
    if(chess[row][col]=='*')return false;
    for(ll prevrow=row-1;prevrow>=1;prevrow--){
        ll prevcol=colposition[prevrow];
        //Vertical Attack
        if(prevcol==col)return false;
        //Diagonal Attack
        if(abs(prevrow-row)==abs(prevcol-col))return false;
    }
    return true;
}
void rec(ll row){
    if(row==n+1){
        ans++;
        return;
    }
    for(ll col=1;col<=8;col++){
        if(valid(row,col)){
            colposition[row]=col;
            rec(row+1);
            colposition[row]=-1;
        }
    }
}
void solve(){
    n=8;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>chess[i][j];
        }
    }
    for(ll i=1;i<=n;i++){
        colposition[i]=-1;
    }
    rec(1);
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
    //cout<<endl;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}
