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
    ll horizontalAttack;
    ll verticalAttack;
    ll totalPosition;
    ll n;
    ll ans;
    cin>>n;
    ll k=1;
    while(k<=n){
        totalPosition=(k*k)*(k*k-1)/2;
        ans=totalPosition;
        if(k>2){
            //Numbers of ways of placing 2x3 or 3x2 in kxk board=(k-1)x(k-2)
            horizontalAttack=2*(k-1)*(k-2);
            verticalAttack=2*(k-1)*(k-2);
            ans=ans-horizontalAttack-verticalAttack;
        }
        cout<<ans<<endl;
        k++;
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