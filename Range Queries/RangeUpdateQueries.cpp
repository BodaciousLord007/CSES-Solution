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
//A)Storage
ll n,q;
ll arr[200100];
ll t[800800];//Segment Tree
 
//B)Function
//I)Initiator
void build(ll index,ll l,ll r){
    //1)Leaf Node
    if(l==r){
        t[index]=0;
        return;
    }
    //2)Division and doing it recursively
    ll mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    //3)Merging both part
    t[index]=t[2*index]+t[2*index+1];
}
//II)Updatation
void update(ll index,ll l,ll r,ll pos,ll diff){
    if(pos<l||pos>r)return;
    if(l==r){
        t[index]+=diff;
        return;
    }
    ll mid=(l+r)/2;
    update(index*2,l,mid,pos,diff);
    update(index*2+1,mid+1,r,pos,diff);
    t[index]=t[2*index]+t[2*index+1];
}
//III)Difference in that range
ll query(ll index,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq)return 0;
    if(lq<=l&&r<=rq){
        //lq<=l<=r<=rq
        return t[index];
    }
    ll mid=(l+r)/2;
    ll ans=query(index*2,l,mid,lq,rq)+query(index*2+1,mid+1,r,lq,rq);
    return ans;
}
//IV)Driver Code
void solve(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n+1);
    while(q--){
        ll decision;
        cin>>decision;
        if(decision==1){
            ll l,r,d;
            cin>>l>>r>>d;
            l--;
            r--;
            update(1,0,n-1,l,d);
            update(1,0,n-1,r+1,-d);
        }
        else{
            ll index;
            cin>>index;
            index--;
            ll ans=query(1,0,n-1,0,index)+arr[index];
            cout<<ans<<endl;
        }
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