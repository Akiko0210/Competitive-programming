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

int dfs(int cur, vector<bool>& vis, vector<int>& memo, vector<int>& nxt) {
    // debug(cur);
    if(memo[cur] >= -1)
        return memo[cur];

    if(vis[cur]) {
        return memo[cur] = -1;
    }
    if(nxt[cur] == -1) {
        return cur;
    }
    vis[cur] = 1;
    memo[cur] = dfs(nxt[cur], vis, memo, nxt);
    vis[cur] = 0;
    return memo[cur];
}

void solve() {
    int n, m;
    cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff;
    }
    
    for(int i = 0; i < n; i++) {
        cin >> a[i].ss;
    }
    cin >> m;
    vector<pii> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i].ff;
    }
    
    for(int i = 0; i < m; i++) {
        cin >> b[i].ss;
    }


    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> defa(n), defb(m);
    defa[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i].second > a[defa[i + 1]].second)
            defa[i] = i;
        else 
            defa[i] = defa[i + 1];
    }

    defb[m - 1] = m - 1;
    for(int i = m - 2; i >= 0; i--) {
        if(b[i].second > b[defb[i + 1]].second) 
            defb[i] = i;
        else 
            defb[i] = defb[i + 1];
    }

    vector<int> nxt(n + m, -1);
    for(int i = 0; i < n; i++) {
        pair<int, int> cur = {a[i].second + 1, 0};
        int ind = lower_bound(b.begin(), b.end(), cur) - b.begin();
        if(ind < m)
            nxt[i] = defb[ind] + n;
    }

    for(int i = 0; i < m; i++) {
        pair<int, int> cur = {b[i].second + 1, 0};
        int ind = lower_bound(a.begin(), a.end(), cur) - a.begin();
        if(ind < n)
            nxt[i + n] = defa[ind];
    }

    // for(int i = 0; i < n + m; i++) {
    //     cout << nxt[i] << " ";
    // }
    // cout << "\n";

    int w = 0, d = 0, l = 0;
    vector<bool> vis(n + m, 0);
    vector<int> memo(n + m, -2);
    for(int i = 0; i < n; i++) {
        int des = dfs(0, vis, memo, nxt);
        // debug(i, des);
        if(des == -1) {
            d++;
            continue;
        }
        if(des < n) {
            w++;
        } else {
            l++;
        }
    }
    cout << w << " " << d << " " << l << "\n";    
}

int main() {
    FAST
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

