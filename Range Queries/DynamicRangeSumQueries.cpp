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
//A)Storage and state declaration
ll n,q;
ll arr[200100];
 
struct node{
    ll val;
};
node t[800800];//Segment Tree
 
//B)Function
//I)Initiator
void build(ll index,ll l,ll r){
    //1)Leaf Node
    if(l==r){
        t[index].val=arr[l];
        return;
    }
    //2)Division and doing it recursively
    ll mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    //3)Merging both part
    t[index].val=t[2*index].val+t[2*index+1].val;
}
//II)Updatation
void update(ll index,ll l,ll r,ll pos,ll newval){
    if(pos<l||pos>r)return;
    if(l==r){
        t[index].val=newval;
        arr[l]=newval;
        return;
    }
    ll mid=(l+r)/2;
    update(index*2,l,mid,pos,newval);
    update(index*2+1,mid+1,r,pos,newval);
    t[index].val=t[2*index].val+t[2*index+1].val;
}
//III)Range Sum Finder
ll query(ll index,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq)return 0;
    if(lq<=l&&r<=rq){
        //lq<=l<=r<=rq
        return t[index].val;
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
    build(1,0,n-1);
    while(q--){
        ll decision;
        cin>>decision;
        if(decision==1){
            ll x,v;
            cin>>x>>v;
            x--;
            update(1,0,n-1,x,v);
        }
        else{
            ll l,r;
            cin>>l>>r;
            l--;
            r--;
            ll ans=query(1,0,n-1,l,r);
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