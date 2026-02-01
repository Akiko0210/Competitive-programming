#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

vector<pair<int, int> > far1(N), far2(N);
vector<int> color(N), p(N), D(3, 0);
vector<bool> vis(N, false);
vector<vector<int> > G(N);

int dfs(int cur, int prev, int c) {
    color[cur] = c;
    p[cur] = prev;
    vis[cur] = 1;
    far1[cur] = far2[cur] = {0, -1};
    for(int x : G[cur]) {
        if(x != prev) {
            int val = dfs(x, cur, c);
            if(val >= far1[cur].first) {
                far2[cur] = far1[cur];
                far1[cur] = {val, x};
            } else if(val > far2[cur].first) {
                far2[cur] = {val, x};
            }
        }
    }
    return far1[cur].first + 1;
}

void dfs2(int i, int prev) {
    vis[i] = 1;
    if(prev != -1) {
        auto fromPar = far1[prev];
        if(fromPar.second == i) {
            fromPar = far2[prev];
        }
        
        if(far1[i].first <= fromPar.first + 1) {
            far2[i] = far1[i];
            far1[i] = {fromPar.first + 1, prev};
        } else if(far2[i].first < fromPar.first + 1) {
            far2[i] = {fromPar.first + 1, prev};
        }
    }
        // cout << "cur = " << i << " " << p[i] << "par\n";
    // cout << far1[i].first << " " << far1[i].second << "\n";
    // cout << far2[i].first << " " << far2[i].second << "\n\n";

    D[color[i]] = max(D[color[i]], far1[i].first + far2[i].first);
    for(int x : G[i]) {
        if(x != prev)
            dfs2(x, i);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 3; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, -1, cnt);
            cnt++;
        }
    }

    vis = vector<bool> (n, 0);

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs2(i, -1);
        }
    }



    // for(int x : D) {
    //     cout << x << "\n";
    // }



    while(q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int ans = far1[x].first + far1[y].first;
        for(int i = 0; i < 3; i++) {
            if(color[x] != i && color[y] != i) {
                ans += D[i];
            }
        }
        cout << ans + 3 << "\n";
    }

    return 0;
}