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
    int n, k, m;
    string s;
    cin >> n >> k >> m >> s;
    vector<int> ind(k, 0);
    vector<vector<int> > pos(k);

    for(int i = 0; i < m; i++) {
        pos[s[i] - 'a'].pb(i);
    }

    int mx = -1;
    string ans = "";
    for(int i = 0; i < n; i++) {
        int nmx = -1, mxchar = -1;
        for(int j = 0; j < k; j++) {
            while(ind[j] < pos[j].size() && pos[j][ind[j]] <= mx) {
                ind[j]++;
            }
            if(ind[j] == pos[j].size()) {
                cout << "NO\n";
                for(; i < n; i++) {
                    ans += char('a' + j);
                }
                cout << ans << "\n";
                return;
            }
            if(nmx < pos[j][ind[j]]) {
                mxchar = j;
                nmx = pos[j][ind[j]];
            }
        }
        ans += char('a' + mxchar);
        mx = nmx;
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

