#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;
int dp[N];
int k[N];

void solve() {
    int hp,a,b,c,d;
    cin>>hp>>a>>b>>c>>d;
    for(int i=1;i<=hp;i++){
        cin >> k[i];
    }
    dp[0] = 0;
    for(int i=1;i<=hp;i++){
        dp[i] = INT32_MAX;
        if(i-b >=0)dp[i] = min(dp[i], dp[i-b]+a);
        else dp[i] = min(dp[i],a);
        if(i-d >=0)dp[i] = min(dp[i], dp[i-d]+c);
        else dp[i] = min(dp[i], c);
        if((i-b*4) >0){
            if( (i-b*4-d-k[i-b*4]) >=0)dp[i] = min(dp[i], dp[i -b*4 -d -k[i-b*4] ] +a*4+c);
            else dp[i] = min(dp[i], a*4+c);
        }
        
        
        
        // dp[i]=min({
        // dp[i-b]+a, 
        // dp[i-d]+c, 
        // dp[i-b*4-d-k[i-b*4]]+a*4+c});
    }

    cout << dp[hp] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}