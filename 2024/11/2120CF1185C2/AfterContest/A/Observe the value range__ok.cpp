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
int a[N];
int sum[N];
int cnt[N];

void solve() {
    int n,m;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
            cin>>a[i];
        sum[i]=sum[i-1]+a[i];

    }


    for(int i=1;i<=n;i++){
        int x=sum[i];
    int ans=0;
        for(int j=100;j>=0;j--){
            if(x>m&&cnt[j]){
                int mm=min(cnt[j],(x - m +j - 1) / j);
                ans+=mm;
                x-=j*mm;

            }
        }
        cnt[a[i]]++;
        cout<<ans<<" ";

    }
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
    string notes;
    cout << "请输入本题的关键要点（如：DP+前缀和）：";
    cin.ignore(); // 清除之前的输入缓冲
    getline(cin, notes);
    
    string current_file = __FILE__;
    string base_name = current_file.substr(0, current_file.length() - 4);
    string new_file = base_name + "_" + notes + "_ok.cpp";
    string filename = new_file.substr(new_file.find_last_of("/\"") + 1);
    
    #ifdef _WIN32
        string command = "rename \"" + current_file + "\" \"" + filename + "\"";
    #else
        string command = "mv \"" + current_file + "\" \"" + new_file + "\"";
    #endif
    
    system(command.c_str());
    cout << "文件已标记为已解决！新文件名：" << filename << endl;
}