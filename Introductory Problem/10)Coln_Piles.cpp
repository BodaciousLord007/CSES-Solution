/*
There are N persons standing in the queue. They are numbered from 1 to N. Hi is the height of the person i. Pi is the 
number of persons who are taller than i and standing in front of i. 
Given these two arrays H and P, your task is to find the actual order of the queue. 
It is guaranteed that the height of each person will be unique.
*/
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
    ll a,b;
    cin>>a>>b;
    if((2*a-b)%3!=0||(2*a-b)<0){
        cout<<"NO"<<endl;
        return;
    }
    swap(a,b);
    if((2*a-b)%3!=0||(2*a-b)<0){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
    cin >> t;
    //cout<<endl;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Test case #"<<i<<endl;
        solve();
    }
    return 0;
}