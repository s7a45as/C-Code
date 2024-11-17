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
    // markAsSolved();
    return 0;
}







// 标记完成函数
void markAsSolved() {
    string current_file = __FILE__;
    string new_file = current_file.substr(0, current_file.length() - 4) + "_ok.cpp";
    
    #ifdef _WIN32
        string command = "rename \"" + current_file + "\" \"" + new_file.substr(new_file.find_last_of("/\\") + 1) + "\"";
    #else
        string command = "mv \"" + current_file + "\" \"" + new_file + "\"";
    #endif
    
    system(command.c_str());
    cout << "File marked as solved!" << endl;
}
