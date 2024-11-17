#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;
int a[N];

void solve() {
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    int ans1=0;
    int ans2=0;
    int t=x;

    for(int i=1;i<=n;i++){
        if(x>0){
            // cout<<"x"<<x<<endl;

            ans1++;
            x-=a[i];

        }
    }
    ans2=min(n,t);

    cout<<ans1<<" "<<ans2<<endl;



}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}