#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 13;

void solve(int n) {
    int x,y,z;
    cin>>x>>y>>z;
    z=2*n-z;
    // cout<<z<<endl;
    int t=__gcd(x,__gcd(y,z));
    // cout<<t<<endl;

    x/=t;
    y/=t;
    z/=t;
    cout<<x<<" "<<y<<" "<<z<<endl;


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
        int n;
        cin>>n;
    while (t--) {

        solve(n);
    }
    
    return 0;
}
