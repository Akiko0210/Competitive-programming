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
    int n, m;
    cin >> n;
    multiset<string> start;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s += ' ';
        start.insert(s.substr(1));
    }
    // for(auto s : start) {
    //     cout << s << "\n";
    // }
    // cout << "\n";
    cin >> m;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        s += ' ';
        char c = s[0];
        s = s.substr(1);
        // cout << s << " = s\n";
        if(c == 'G' && start.find(s) != start.end()) {
            ans ++;
            start.erase(start.find(s));
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

