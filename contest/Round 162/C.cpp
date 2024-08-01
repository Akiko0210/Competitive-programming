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
    int n, q;
    cin >> n >> q;
    vector<int> c(n), cnt(n, 0);
    vector<ll> pre(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        pre[i] = c[i];
        cnt[i] += c[i] == 1;

        if(i > 0) {
            pre[i] += pre[i - 1];
            cnt[i] += cnt[i - 1];
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        r--, l--;
        if(l == r) {
            cout << "NO\n";
            continue;
        }
        ll len = r - l + 1, sum = pre[r] - (l > 0 ? pre[l - 1] : 0), ones = cnt[r] - (l > 0 ? cnt[l - 1] : 0);
        if(sum - ones * 2 >= len - ones) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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

