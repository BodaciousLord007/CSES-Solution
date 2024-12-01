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
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>g(n+1);
    for(ll i=0;i<m;i++){
        ll x,y,d;
        cin>>x>>y>>d;
        g[x].push_back(MP(y,d));
    }
    vector<ll>dis(n+1,1e18);
    priority_queue<pair<ll,ll>>pq;
    pq.push(MP(-0,1));
    vector<bool>vis(n+1,false);
    dis[1]=0;
    while(!pq.empty()){
        ll currentnode=pq.top().S;
        pq.pop();
        if(vis[currentnode]==true)continue;
        vis[currentnode]=true;
        for(auto v:g[currentnode]){
            ll nextnode=v.F;
            ll weight=v.S;
            if(dis[nextnode]>dis[currentnode]+weight){
                dis[nextnode]=dis[currentnode]+weight;
                pq.push(MP(-dis[nextnode],nextnode));
            }
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<dis[i]<<" ";
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
