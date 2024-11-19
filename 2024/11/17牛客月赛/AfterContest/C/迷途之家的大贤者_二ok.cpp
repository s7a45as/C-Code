#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e4 + 5, M = 17;

int n;
map<int, int> cnt[2], del[2];

void solve()
{
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            cnt[i][x]++;
        }
    }
    int v[2] = { 0 };
    for (int i = 0; i < 2; i++) {
        for (auto& it : cnt[i]) {
            if (it.second >= 2) {
                v[i] += it.second - 1;
            }
            it.second = 1;
        }
    }
    int ans = max(v[0], v[1]);
    // cout << ans << '\n';
    int add = 0;
    int tmp = abs(v[0] - v[1]);
    for (auto it : cnt[0]) {
        int x = it.first;
        if (cnt[1].count(x)) {
            add++;
        }
    }
    add = max(0ll, (add - tmp + 1) / 2);
    ans += add;
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}