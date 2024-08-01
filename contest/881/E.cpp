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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> seg(m);
    for(int i = 0; i < m; i++) {
        cin >> seg[i].ff >> seg[i].ss;
    }
    sort(seg.begin(), seg.end());
    int q;
    cin >> q;
    vector<int> p(n + 1, 0);
    for(int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        p[x] = i;
    }

    int ind = 0, ans = -1;
    queue<int> qu;
    set<int> s;

    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) continue;

        if(i >= seg[ind].ff && i <= seg[ind].ss) {
            qu.push(i);
            s.insert(p[i]);
        }

        if(i > seg[ind].ss) {
            ind++;
        }

        while(qu.front() < seg[ind].ff) {
            int cur = qu.front();
            s.erase(p[cur]);
            qu.pop();
        }

        int range = seg[ind].ss - seg[ind].ff;
        if(range / 2 + 1 <= qu.size()) {
            // auto it = s.begin() + range / 2;
        }
    }
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
