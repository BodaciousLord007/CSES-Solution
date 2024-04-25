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
ll n,q;
ll arr[200100];
 
struct node{
    ll totalsum=0;
    ll leftsum=0;
    ll rightsum=0;
    ll maxsum=0;
};
node t[800800];//Segment Tree
 
//B)Function
//I)Initiator
void build(ll index,ll l,ll r){
    //1)Leaf Node
    if(l==r){
        t[index].totalsum=arr[l];
        t[index].leftsum=arr[l];
        t[index].rightsum=arr[l];
        t[index].maxsum=max(arr[l],0LL);
        return;
    }
    //2)Division and doing it recursively
    ll mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    //3)Merging both part
    t[index].totalsum=t[2*index].totalsum+t[2*index+1].totalsum;
    t[index].leftsum=max(t[2*index].leftsum,t[2*index].totalsum+t[2*index+1].leftsum);
    t[index].rightsum=max(t[2*index].rightsum+t[2*index+1].totalsum,t[2*index+1].rightsum);
    t[index].maxsum=max(max(t[2*index].maxsum,t[2*index+1].maxsum),t[2*index].rightsum+t[2*index+1].leftsum);
 
}
//II)Updatation
void update(ll index,ll l,ll r,ll pos,ll newval){
    if(pos<l||pos>r)return;
    if(l==r){
        t[index].totalsum=newval;
        t[index].leftsum=newval;
        t[index].rightsum=newval;
        t[index].maxsum=max(newval,0LL);
        arr[l]=newval;
        return;
    }
    ll mid=(l+r)/2;
    update(index*2,l,mid,pos,newval);
    update(index*2+1,mid+1,r,pos,newval);
    //3)Merging both part
    t[index].totalsum=t[2*index].totalsum+t[2*index+1].totalsum;
    t[index].leftsum=max(t[2*index].leftsum,t[2*index].totalsum+t[2*index+1].leftsum);
    t[index].rightsum=max(t[2*index].rightsum+t[2*index+1].totalsum,t[2*index+1].rightsum);
    t[index].maxsum=max({t[2*index].maxsum,t[2*index+1].maxsum,t[2*index].rightsum+t[2*index+1].leftsum});
}
//C)Driver Code
void solve(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build(1,0,n-1);
    while(q--){
        ll index,value;
        cin>>index>>value;
        index--;
        update(1,0,n-1,index,value);
        cout<<max(t[1].maxsum,0LL)<<endl;
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