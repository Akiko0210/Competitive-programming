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
    ll n, k;
    cin >> n >> k;
    vector<vector<ll> > lab(n, vector<ll> (3));
    for(int i = 0; i < n; i++) {
        cin >> lab[i][0] >> lab[i][1] >> lab[i][2];
    }
    /*
    S[i] = a[i] + b[i] + c[i];

    we want to maximize (min S[i]).
    a) if a == b == c -> we can't do anything 
    if not a but if a <= b <= c -> we can only decrease at first until we're able to increase.
    enable cost: b - a + 1 if (a < c) or c - b + 1 if (a < b)
    otherwise we can icnrease the sum by at least 1.
    */

    long long fixed = 2e18;
    vector<pair<ll, ll> > movable;
    for(int i = 0; i < n; i++) {
        ll sum = lab[i][0] + lab[i][1] + lab[i][2];
        // debug(sum);
        if(lab[i][0] == lab[i][1] && lab[i][1] == lab[i][2]) {
            fixed = min(fixed, sum);
        } else {
            // movable.pb(sum);
            if(lab[i][0] <= lab[i][1] && lab[i][1] <= lab[i][2]) {
                ll enable = 1e18;

                // we can make b < a eventually then spam c += sign(a - b)
                // a just can't be equal to c
                // if(lab[i][0] < lab[i][2]) {
                enable = min(enable, lab[i][1] - lab[i][0] + 1);
                // }

                // we can make c < b eventually then spam a += sign(b - c)
                // a may be equal to b in such case, b can't be equal to c.
                
                // if(lab[i][0] < lab[i][1]) {
                enable = min(enable, lab[i][2] - lab[i][1] + 1 + (lab[i][0] == lab[i][1]));
                // }

                // if b < c, we don't gain anything by decreasing a. Or maybe
                // we decrease a first then perform above 2.

                movable.pb({sum, enable * 2});
            } else {
                movable.pb({sum, 0});
            }
        }
    }
    if(movable.empty()) {
        cout << fixed << "\n";
        return;
    }
    sort(movable.begin(), movable.end());
    ll last = min(movable[0].first, fixed);
    n = movable.size();
    for(int i = 0; i < n && k >= 0 && last < fixed; i++) {
        // cur ceiling is at movable[i], we're moving i + 1 things at the same time.
        // next ceiling is min(movable[i + 1], fixed);

        ll ceiling = min(i == n - 1 ? (ll)(2e18) : movable[i + 1].first, fixed);
        ll dis = ceiling - last;
        // first we need to pay the enable cost.
        k = max(0LL, k - movable[i].ss);
        // after paying movable[i].ss, movable[i].ff  = movable[i].ff - movable[i].ss
        
        if(dis <= k / (i + 1)) {
            last = ceiling;
            k -= dis * (i + 1);
        } else {
            last += k / (i + 1);
            k = 0;
        }
    }

    cout << last << "\n";


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
 
