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
    ll x, m, ans = 0, bx = 1;
    cin >> x >> m;
    while(bx <= x) {
        bx <<= 1;
    }

    for(ll y = 1; y <= min(bx - 1, m); y++) {
        ll c = x ^ y;
        if((c % x == 0) || (c % y == 0)) {
            ans ++;
            debug(y);
        }
    }
    debug(ans);

    if(m <= bx - 1) {
        cout << ans << "\n";
        return;
    }

    /*
        (p * bx + d) % x == 0
        y = p * bx + (x ^ d) <= m
                        r
    */
    ll mrem = m % bx, total = m / bx, currem = bx % x, cnt = 0;
    vector<bool> posrem(x, false);
    while(!posrem[currem]) {
        posrem[currem] = 1;
        currem = (currem + bx) % x;
        cnt++;
    }
    debug(total, cnt);
    currem = bx % x;
    vector<ll> cntrem(x, 0);
    while(posrem[currem]) {
        posrem[currem] = false;
        cntrem[currem] = total / cnt;
        currem = (currem + bx) % x;
    }

    currem = bx % x;
    ll temp = total % cnt;
    while(temp--) {
        cntrem[currem]++;
        currem = (currem + bx) % x;
    }
    ll lastrem = (currem - bx % x + x) % x;

    for(int i = 0; i < x; i++) {
        debug(i, cntrem[i]);
    }
    // cntrem[lastrem]-- if 

    for(ll r = 0; r < bx; r++) {
        // y = p * bx + r <= m
        // c = x ^ y = p * bx + (r ^ x)
        ll d = r ^ x, remseek = ((x - d) % x + x) % x;
        debug(d, cntrem[remseek], remseek, r);
        // p * bx % x == remseek
        ans += cntrem[remseek];
        if(remseek == lastrem && r > mrem) {
            debug(mrem, r, lastrem);
            ans--;
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

