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
const int N = 1e7 + 1;

vector<bool> p(N, true);
vector<int> primes;

void sieve() {
    for(int i = 2; i < N; i++) {
        if(p[i]) {
            primes.pb(i);
            for(ll j = (ll)i * i; j < N; j += i) {
                p[j] = false;
            }
        }
    }
}

void solve() {
    sieve();
    // debug(primes.size());
    // cout << primes.back() << "\n";
    string s;
    cin >> s;
    int n = s.size();
    for(int x : primes) {
        string t = to_string(x);
        if(t.size() < n) continue;
        if(t.size() > n) break;

        bool match = true;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((s[i] == s[j]) != (t[i] == t[j])) {
                    match = false;
                }
            }
        }
        if(match) {
            cout << x << "\n";
            return;
        }
    }
    cout << "-1\n";
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

