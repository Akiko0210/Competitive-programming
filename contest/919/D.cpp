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
    vector<ll> ar, sz, a;
    ll s = 0, mx = 1e18;
    bool overflow = false;

    for(int i = 0; i < n; i++) {
        int b, x;
        cin >> b >> x;
        if(overflow) continue;

        if(b == 1) {
            a.pb(x);
            s++;
            ar.pb(s);
            sz.pb(a.size());
        } else {
            if(mx / x < s) {
                overflow = true;
                continue;
            }

            s += s * x;
            ar.pb(s);
            sz.pb(a.size());
        }
    }

    while(q--) {
        ll k;
        cin >> k;
        while(k > 0) {
            int ind = upper_bound(ar.begin(), ar.end(), k) - ar.begin();
            ind--;
            if(k % ar[ind] == 0) {
                cout << a[sz[ind] - 1] << " ";
                break;
            }
            k %= ar[ind];
        }
    }
    cout << "\n";
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

