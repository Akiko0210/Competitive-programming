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
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    vector<int> pos = {-1};
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') pos.pb(i);
    }

    pos.pb(n);
    for(int i = 1; i < pos.size(); i++) {
        // if(pos[i] - pos[i - 1] - 1 > k) {
        //     cout << "NO\n";
        //     return;
        // }
        for(int j = pos[i - 1] + m; j < pos[i]; j++) {
            if(s[j] == 'C') {
                cout << "NO\n";
                return;
            }
            k--;
            if(k < 0) {
                cout << "NO\n";
                return;
            }
        }
        // debug(k);
    }
    cout << "YES\n";
}

int main() {
    int t;
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

