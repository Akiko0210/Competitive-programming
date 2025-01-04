#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

vector<int> cnt(N + 1, 0);
// cnt[x] is number of leaf node rooted at x.
vector<vector<int> > G(N + 1);

int dfs(int curnode, int parentnode) {
    bool isleaf = true;
    for(int childnode : G[curnode]) {
        if(childnode != parentnode) {
            isleaf = false;
            cnt[curnode] += dfs(childnode, curnode);
        }
    }

    cnt[curnode] += isleaf;
    return cnt[curnode];
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        cnt[i] = 0;
        G[i].clear();
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    dfs(1, 0);
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << (long long)cnt[x] * (long long)cnt[y] << "\n";
    }


}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}