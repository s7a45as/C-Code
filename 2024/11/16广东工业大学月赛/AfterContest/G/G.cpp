#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;
vector<int>v;


void solve() {
    int n,k;
    cin>>n>>k;
    if(k<=n/2){
        int kk = n/2+1;
        cout<<"YES"<<endl;
        cout<<n/2+1<<" ";
        for(int i=1;i<=(n-1)/2;i++){
            cout << i << " " << i+kk << " ";
        }
        if(n%2 == 0) cout << n/2 << " "; 
        cout<<endl;

    }else{
        cout<<"NO"<<endl;
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