#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 13;

int euler_one(int n){
    int ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;

        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;

}

void solve() {
    int n;
    cin>>n;
    cout<<euler_one(n)<<endl;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
