#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;

void solve() {

    int r,b,k;
    cin>>r>>b>>k;
    
    if(k==1){
         cout<<"REBEL"<<endl;
         return ;

    }
   
    //r*k<=b
    if(min(r,b)*(k-1)<max(r,b)){
    cout<<"REBEL"<<endl;
    }else{
            cout<<"OBEY"<<endl;
    }   

    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}