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
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

const ll MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > G(n + 1);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    string s;
    cin >> s;
    int cnt[2] = {0, 0};
    int q = 0, tq = 0;
    vector<int> leaves;
    for(int i = 2; i <= n; i++) {
        if(G[i].size() == 1) leaves.pb(i - 1);
        else {
            if(s[i - 1] == '?') tq++;
        }
    }

    for(int i : leaves) {
        if(s[i] == '?') {
            q++;
        } else {
            cnt[s[i] - '0']++;
        }
    }

    if(s[0] == '?') {
        if(cnt[0] != cnt[1])
            cout << max(cnt[0], cnt[1]) + q / 2 << "\n";
        else {
            if(q & 1) {
                cout << cnt[0] + q / 2 + (tq & 1) << "\n";
            } else {
                cout << cnt[0] + q / 2 << "\n";
            }
        }
    } else {
        cout << (cnt[1 - s[0] + '0'] )+ (q + 1) / 2 << "\n";
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

