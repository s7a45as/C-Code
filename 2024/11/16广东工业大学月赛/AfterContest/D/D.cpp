#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = (int)2E9;
const int N=1e6+1213;

int n,k;
int w[N];
bool  so(int a)
{
    int val =1;
    int sum = 0;
    for(int i=0;i<n;++i){
        sum += w[i];
        if(sum > a){
            sum = w[i];
            val ++;
        }
    }
    return val <= k;
}
void solve() {

    cin >> n >> k;
    for(int i=0;i<n;++i){
        cin >> w[i];
    }
    int l = 0,r = 1e18;
    while(l<r){
        int mid = (l+r)/2;
        if(so(mid)){
            r = mid -1;
        }else{
            l = mid +1;
        }
    }
    if(!so(l))l++;
    cout << l << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}