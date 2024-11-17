#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;
int a[N];
int sum1[N];
int sum2[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+a[i]*a[i];
        sum2[i]=sum2[i-1]+a[i]*2;

    }

    
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int ans1=sum1[r]-sum1[l-1];
        int ans2=(sum2[r]-sum2[l-1])*k;
        int ans=ans1+ans2+k*k*(r-l+1);
        cout<<ans<<endl;

    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}