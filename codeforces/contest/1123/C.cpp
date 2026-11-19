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
const int N = 3e5 + 5;

vector<bool> isp(N, true);
vector<ll> primes;

void sieve() {
    for(ll i = 2; i < N; i++) {
        if(isp[i]) {
            primes.pb(i);
            for(ll j = i * i; j < N; j += i) {
                isp[j] = false;
            }
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    // debug(n, x);
    vector<int> a(n), xprimes;

    for(ll p : primes) {
        // debug(p);
        if(p * p > x) {
            break;
        }

        if(x % p == 0) {
            xprimes.pb(p);
            while(x % p == 0)
                x /= p;
        }
    }

    if(x > 1) {
        xprimes.pb(x);
    }

    // for(int p : xprimes) {
    //     cout << p << " ";
    // }
    // cout << "\n";
    // debug(xprimes.size());
    vector<ll> sum((int)xprimes.size(), 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < xprimes.size(); j++) {
            if(a[i] % xprimes[j] == 0) {
                sum[j] += a[i];
            }
        }
    }
    if(sum.empty()) {
        cout << "0\n";
        return;
    }
    cout << *max_element(sum.begin(), sum.end()) << "\n";
}

int main() {
    sieve();
    debug(primes.back());
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

