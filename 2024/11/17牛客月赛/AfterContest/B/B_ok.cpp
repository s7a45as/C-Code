#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define endl '\n'
void  markAsSolved();
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 13;



void solve() {
 int n, m;
    cin >> n >> m;
    vector<string> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int mx = 0;
    int X1 = 1, Y1 = 1, X2 = 1, Y2 = 1;
    for(int x1 = 0; x1 < n; x1++){
        for(int y1 = 0; y1 < m; y1++){
            for(int x2 = x1; x2 < n; x2++){
                for(int y2 = y1; y2 < m; y2++){
                    bool flag = true;
                    for(int i = x1; i <= x2 && flag; i++){
                        for(int j = y1; j <= y2 && flag; j++){
                            if(nums[i][j] == '*'){
                                flag = false;
                            }
                        }
                    }
                    if(flag){
                        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                        if(area > mx){
                            mx = area;
                            X1 = x1 + 1;
                            Y1 = y1 + 1;
                            X2 = x2 + 1;
                            Y2 = y2 + 1;
                        }
                    }
                }
            }
        }
    }
    cout << X1 << " " << Y1 << " " << X2 << " " << Y2;
    
}

signed main() {
    markAsSolved();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t; 
    while (t--) {
        solve();
    }
    
    // 取消下面的注释来标记题目为已完成
    // 
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
