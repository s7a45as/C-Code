#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 13;

void solve() {
    string s;
    cin>>s;
    int ans=0;
  int num=0;
  int tnum=0;

  int fa=0;
    for(int i=0;i<s.size();i++){
    
        if(s[i]=='G'){
            num++;
        }else if(s[i]!='G'&&s[i]!='1'){
          num=0;

        }else if(s[i]=='1'){
          if (num > 0)
             if(num%2==0){
                if(fa==0){
                    fa=1;
                    ans++;

                }
             }else{
                ans++;
                
             }
            num=0;
        }
    }

      cout<<ans<<endl;

    
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
