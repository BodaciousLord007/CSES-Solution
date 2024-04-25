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
//A)Storage and node
struct node{
    ll val;
    ll freq;
};
ll n,q;
ll arr[200100];
node t[800800];//Segment Tree
//B)Function
//I)Initiator
void build(ll index,ll l,ll r){
    //1)Leaf Node
    if(l==r){
        t[index].val=arr[l];
        t[index].freq=1;
        return;
    }
    //2)Division and doing it recursively
    ll mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    //3)Merging both part
    if(t[2*index].val==t[2*index+1].val){
        t[index].val=t[2*index].val;
        t[index].freq=t[2*index].freq+t[2*index+1].freq;
    }
    else if(t[2*index].val<t[2*index+1].val){
        t[index].val=t[2*index].val;
        t[index].freq=t[2*index].freq;
    }
    else{
        t[index].val=t[2*index+1].val;
        t[index].freq=t[2*index+1].freq;
    }
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
    if(t[2*index].val==t[2*index+1].val){
        t[index].val=t[2*index].val;
        t[index].freq=t[2*index].freq+t[2*index+1].freq;
    }
    else if(t[2*index].val<t[2*index+1].val){
        t[index].val=t[2*index].val;
        t[index].freq=t[2*index].freq;
    }
    else{
        t[index].val=t[2*index+1].val;
        t[index].freq=t[2*index+1].freq;
    }
}
//III)Min Sum Finder
node query(ll index,ll l,ll r,ll lq,ll rq){
    if(l>rq||r<lq){
        node temp;
        temp.val=1e18;
        return temp;
    }
    if(lq<=l&&r<=rq){
        //lq<=l<=r<=rq
        return t[index];
    }
    ll mid=(l+r)/2;
    node leftnode=query(index*2,l,mid,lq,rq);
    node rightnode=query(index*2+1,mid+1,r,lq,rq);
    if(leftnode.val==rightnode.val){
        node ans;
        ans.val=leftnode.val;
        ans.freq=leftnode.freq+rightnode.freq;
    }
    else if(leftnode.val<rightnode.val){
        return leftnode;
    }
    else{
        return rightnode;
    }
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
            node ans=query(1,0,n-1,l,r);
            cout<<ans.val<<endl;
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