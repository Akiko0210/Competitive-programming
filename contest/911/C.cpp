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

// int dfs(int cur, vector<int>& dp, string& s, vector<int>& p) {
//     if(cur == 0) {
//         return 0;
//     }

// }

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int l[n + 1], r[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    queue<int> q;
    q.push(1);
    vector<int> p(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(l[cur] > 0) {
            p[l[cur]] = cur;
            cnt[l[cur]] = cnt[cur] + (s[cur - 1] != 'L');
            // debug(cur, cnt[cur], cnt[l[cur]], l[cur], s[cur - 1]);
            q.push(l[cur]);
        }
        if(r[cur] > 0) {
            p[r[cur]] = cur;
            cnt[r[cur]] = cnt[cur] + (s[cur - 1] != 'R');
            // debug(cur, cnt[cur], cnt[r[cur]], r[cur], s[cur - 1], s[cur - 1] != 'R');
            q.push(r[cur]);
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     cout << cnt[i] << " ";
    // }
    // cout << "\n";

    int ans = INF;
    for(int i = 1; i <= n; i++) {
        if(l[i] == 0 && r[i] == 0) {
            ans = min(ans, cnt[i]);
        }
    }

    cout << ans << "\n";


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

