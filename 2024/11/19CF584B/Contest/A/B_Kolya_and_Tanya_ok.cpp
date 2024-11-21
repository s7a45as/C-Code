#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
void markAsSolved();
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 13;

long long ksm(long long a, long long b) {
int m=MOD;

  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}



void solve() {
    int n;
    cin>>n;

    // cout<<endl;

    // cout<<pow(27,n)<<endl;
    // cout<<pow(7,n)<<endl;
    // if(pow(27,n)<pow(7,n))cout<<"true"<<endl;
    // else cout<<"false"<<endl;

    // cout<<ksm(27LL,n)%MOD<<endl;
    // cout<<ksm(7LL,n)%MOD<<endl;

    cout<<(ksm(27LL,n)%MOD-ksm(7LL,n)%MOD+MOD)%MOD<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    // 取消下面的注释来标记题目为已完成
    markAsSolved();
    return 0;
}

// 标记完成函数
void markAsSolved() {
    string current_file = __FILE__;
    string new_file = current_file.substr(0, current_file.length() - 4) + "_ok.cpp";
    string filename = new_file.substr(new_file.find_last_of("/\"") + 1);
    
    #ifdef _WIN32
        string command = "rename \"" + current_file + "\" \"" + filename + "\"";
    #else
        string command = "mv \"" + current_file + "\" \"" + new_file + "\"";
    #endif
    
    system(command.c_str());
    cout << "File marked as solved!" << endl;
}