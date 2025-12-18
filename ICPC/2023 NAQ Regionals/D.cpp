#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF 1e6
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
}

int main() {
    int r, c, d, n;
    cin >> r >> c >> d >> n;
    vector<pii> pos(n);
    unordered_map<int, map<int, int> > line;
    for(int i = 0; i < n; i++) {
        cin >> pos[i].ff >> pos[i].ss;
        line[pos[i].ff][pos[i].ss] += INF;
        line[pos[i].ff][pos[i].ss + 1] -= INF;
        int top = min(pos[i].ff + d, r);
        int bottom = max(pos[i].ff - d, 1);
        for(int j = bottom; j <= top; j++) {
            int abs_diff = sqrt(d * d - (pos[i].ff - j) * (pos[i].ff - j));
            int left = max(1, pos[i].ss - abs_diff), right = min(c, pos[i].ss + abs_diff);
            line[j][left]++;
            line[j][right + 1]--;
        }
    }
    int ans = INF;
    for(auto &[row, m] : line) {
        int cur = 0;
        m[1];
        m[c];
        for(auto &[col, cnt] : m) {
            cur += cnt;
            if(col <= c)
                ans = min(ans, cur);
        }
        if(ans == 0) {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

