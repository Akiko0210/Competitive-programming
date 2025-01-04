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
const ll N = 1e7 + 1;

vector<int> primes, ans(N, 0);
vector<bool> p(N, 0);

void sieve() {
    for(ll i = 2; i < N; i++) {
        if(!p[i]) {
            primes.pb(i);
            for(ll j = i * i; j < N; j += i) {
                p[j] = true;
            }
        }
    }
}

void printans(int t, int ans) {
    cout << "Case #" << t << ": " << fixed << setprecision(6) << ans << "\n";
}

int solve() {
    int n;
    cin >> n;
    return ans[n];
}

int main() {
    sieve();

    ans[5] = 2;
    for(int i = 6; i < N; i++) {
        ans[i] = ans[i - 1] + (!p[i] && !p[i - 2]);
    }

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        printans(i, solve());
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

