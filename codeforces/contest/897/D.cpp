#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF INT_MAX
using namespace std;
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef AKIKO_DEBUG
#define debug(...) cerr << "\033[1;31m(" << #__VA_ARGS__ << "):\033[0m", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll MOD = 1e9 + 7;

int dfs(int& cur, int ind, vector<bool>& curvis, vector<int>& vis, vector<int>& a) {
    if(curvis[cur]) {
        return -1;
    }
    if(vis[cur]) {
        return ind - vis[cur];
    }
    vis[cur] = ind;
    int ans = dfs(a[cur], ind + 1, curvis, vis, a);
    curvis[cur] = 1;
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), vis(n, 0);
    vector<bool> curvis(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    if(k == 1) {
        for(int i = 0; i < n; i++) {
            if(a[i] != i) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        int cur = i, len = dfs(cur, 1, curvis, vis, a);
        // debug(len);
        if(len != -1 && len != k) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
