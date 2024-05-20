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
#define all(x) (x).begin(), (x).end()
//***********************************************************************************
string pathway;
bool matrix[9][9];
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
map<char,ll>getdir;
bool valid(ll x,ll y){
    if(x<1||y<1)return false;
    if(x>7||y>7)return false;
    if(matrix[x][y]==true)return false;
    return true;
}
ll operation=0;
ll rec(ll level,ll x,ll y){
    //1)Base Case
    //i)Complete Path
    if(level==48){
        if(x==7&&y==1)return 1;
        else return 0;
    }
    //ii)Division of 2 parts
    //i)Up and Down Closed,Left and Right Open
    if(matrix[x-1][y]==true&&matrix[x+1][y]==true&&matrix[x][y-1]==false&&matrix[x][y+1]==false)return 0;
    //ii)Up and Down Open,Left and Right Closed
    if(matrix[x-1][y]==false&&matrix[x+1][y]==false&&matrix[x][y-1]==true&&matrix[x][y+1]==true)return 0;
    //iii)Reach EndPoint Prmaturely
    //2)Transition
    if(x==7&&y==1)return 0;
    ll ans=0;
    if(pathway[level]=='?'){
        for(ll dir=0;dir<4;dir++){
            ll newx=x+dx[dir];
            ll newy=y+dy[dir];
            if(valid(newx,newy)){
                if(newx<1||newy<1)continue;
                if(newx>7||newy>7)continue;
                matrix[newx][newy]=true;
                ans+=rec(level+1,newx,newy);
                matrix[newx][newy]=false; 
            }
        }
    }
    else{
        ll newx=x+dx[getdir[pathway[level]]];
        ll newy=y+dy[getdir[pathway[level]]];
        if(valid(newx,newy)){
            matrix[newx][newy]=true;
            ans+=rec(level+1,newx,newy);
            matrix[newx][newy]=false;
        }
    }
    //3)Return Answer
    return ans;
}
void solve(){
    memset(matrix,false,sizeof(matrix));
    matrix[1][1]=true;
    cin>>pathway;
    getdir['U']=3;
    getdir['D']=2;
    getdir['L']=1;
    getdir['R']=0;
    for(ll i=0;i<=8;i++){
        matrix[0][i]=true;
        matrix[8][i]=true;
        matrix[i][0]=true;
        matrix[i][8]=true;
    }
    cout<<rec(0,1,1);
}
//************************************************************************************
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