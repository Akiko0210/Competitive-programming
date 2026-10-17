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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), sum1(n), sum2(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum1[i] = a[i];
        if(i > 0) {
            sum1[i] += sum1[i - 1];
        }
        sum2[i] = sum1[i];
        if(i > 0) {
            sum2[i] += sum2[i - 1];
        }
    }

    auto query = [&](ll r) -> ll {
        // largest s; s * (s + 1) / 2 < r
        ll s = sqrt(r * 2) + 3;
        while(s * (s + 1) / 2 > r) {
            s--;
        }

        ll sum = (s > 0 ? sum2[s - 1] : 0), rem = r - s * (s + 1) / 2;
        // debug(rem);
        if(rem > 0) 
            sum += sum1[rem - 1];
        return sum;
    };

    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << "\n";
    }
    /*
    1 10 100 1000
    1 1 10 1 10 100 1 10 100 1000
    
    */
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

