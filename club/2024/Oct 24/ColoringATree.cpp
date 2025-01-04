#include <iostream>
#include <vector>

using namespace std;

vector<int> p, c;
vector<vector<int> > G;

int dfs(int cur) {
    int ans = 0;
    for(int x : G[cur]) 
        ans += dfs(x) + (c[cur] != c[x]);
    return ans;
}

int main() {
    int n;
    cin >> n;
    p.resize(n + 1, 0);
    c.resize(n + 1, 0);
    G.resize(n + 1);

    for(int i = 2; i <= n; i++) {
        cin >> p[i];
        G[p[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    cout << dfs(1) + 1 << "\n";




    return 0;
}