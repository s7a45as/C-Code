#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e7 + 13;

int n,prime[N],cnt;
bool vis[N];
void get_prime(){
    for(int i=2;i<=N;i++){
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=N;j++){
            vis[i*prime[j]]=true;
            if(i%prime[j]==0)break;


        }
    }
}


void solve() {
    cin>>n;
    get_prime();
    n++;
    cout<<prime[n]<<endl;
    
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
