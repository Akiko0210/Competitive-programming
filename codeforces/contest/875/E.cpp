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

const ll MOD = 998244353;
const ll N = 1e3;
vector<ll> pos(N + 1, 0);

void calc_pos() {
    vector<ll> nest(N + 1, 0);
    pos[1] = nest[1] = 1;
    /*
        nest[i] = pos[i - 1]
        pos[i] = nest[i] + nest[i - 1] * pos[1] = nest[i - 2] * pos[2] + ... nest[1] * pos[n - 1]
    */
    for(int i = 2; i <= N; i++) {
        nest[i] = pos[i - 1];
        pos[i] = nest[i];
        for(int j = 1; j < i; j++) {
            (pos[i] += nest[j] * pos[i - j] % MOD) %= MOD;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    set<pii> s;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        s.insert({x, y});
    }

    vector<pii> fixed_segs;
    while(s.size() > 1) {
        pii cur = *s.begin();
        s.erase(cur);
        pii nxt = *s.begin();

        if(cur.ff < nxt.ff && cur.ss < nxt.ss) {
            s.insert(cur);
            continue;
        }
        
        if(cur.ss < nxt.ff) {
            fixed_segs.pb(cur);
            continue;
        }

        s.erase(nxt);
        if(nxt.ff > cur.ff)
            s.insert({cur.ff, nxt.ff - 1});
        s.insert({nxt.ff, cur.ss});
        if(cur.ss < nxt.ss)
            s.insert({cur.ss + 1, nxt.ss});



    }

}

int main() {
    calc_pos();
    cout << pos[50] * pos[50] % MOD * pos[50] % MOD * pos[50] % MOD * pos[201] % MOD * pos[99] % MOD << "\n";
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
