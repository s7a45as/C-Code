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
bool vis[N];
int book[N];
int n,m;
vector<int>G[N];
vector<int>ans[5];
bool dfs(int u,int k)
{
    vis[u]=1;
    book[u]=k;
    ans[k].push_back(u);
    for(auto v:G[u]){
        if(!vis[v]){
            if(k==1&&dfs(v,2))return true;
            if(k==2&&dfs(v,1))return true;
            
        }else if(vis[v]&&book[v]==k)return true;

    }
    return false;

}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);

    }
    for(int i=1;i<=n;i++){
        if(G[i].size()>0&&vis[i]==0){
            if(dfs(i,1)){
                cout<<-1<<endl;
                return ;

            }
        }
    }
     cout<<ans[1].size()<<endl;
    for(auto x:ans[1])
    	cout<<x<<" ";
    cout<<endl;
    cout<<ans[2].size()<<endl;
    for(auto x:ans[2])
        cout<<x<<" ";
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
      markAsSolved();
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