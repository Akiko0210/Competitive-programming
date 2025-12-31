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
unordered_map<ll, ll> memo;

ll key(int l, int r) {
    return (ll)l * 1e6 + r;
}

ll query(int l, int r) {
    ll k = key(l, r);
    if(memo.find(k) != memo.end()) {
        return memo[k];
    }
    cout << "? " << l << ' ' << r << endl;
    ll sum;
    cin >> sum;
    return memo[k] = sum;
}

void answer(ll ans) {
    cout << "! " << ans << endl;
    memo.clear();
}

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;
    ll sum = query(1, n);
    while(l < r) {
        // find pivot
        int l1 = l, r1 = r;
        while(l1 < r1) {
            int m = (l1 + r1) / 2;
            ll s = query(l, m);
            if(s * 2 < sum) {
                l1 = m + 1;
            } else if(s * 2 > sum) {
                r1 = m - 1;
            } else {
                l1 = r1 = m;
            }
        }
        int p = l1;
        if(p - l + 1 > r - p) {
            l = p + 1;
        } else {
            r = p;
        }
        sum /= 2;
    }

    answer(sum);
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

