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
const int N = 1e7;

vector<int> primes, m(N + 1, 0);
vector<bool> p(N + 1, true), ignored(N + 1, false);

void sieve() {
    for(int i = 2; i <= N; i++) {
        if(!m[i]) {
            primes.push_back(i);
            for(int j = i * 2; j <= N; j += i) {
                // p[j] = false;
                m[j]++;
                if(j % ((ll)i * i) == 0) {
                    ignored[j] = true;
                }
            }
        }
    }
}

ll calc(ll N, ll M) {
    ll total = N * M;
    for(int i = 2; i <= min(N, M); i++) {
        if(ignored[i]) continue;
        ll cur;
        if(m[i] == 0) {
            cur = (N / i) * (M / i);
        } else if(m[i] & 1) {
            cur = (N / i) * (M / i);
        } else {
            cur = -(N / i) * (M / i);
        }
        // debug(i, cur);
        total -= cur;
    }
    // debug(N, M, total);
    return total;
}

int main() {
    sieve();
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << calc(b, d) - calc(b, c - 1) - calc(a - 1, d) + calc(a - 1, c - 1) << "\n";

    /*
        coprimes = total - non coprime pairs. 

    */
    // int ans = 0;
    // for(int i = 1; i < 1e7; i++) {
    //     ans += 1e7 / i;
    // }
    // cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

