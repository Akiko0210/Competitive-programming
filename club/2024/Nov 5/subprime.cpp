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
const int N = 1e6 + 5e5;

vector<bool> p(N, 0);
vector<int> primes;

void sieve() {
    for(ll i = 2; i < N; i++) {
        if(!p[i]) {
            primes.pb(i);
            for(ll j = i * i; j < N; j += i) {
                p[j] = 1;
            }
        }
    }
}

int main() {
    sieve();
    // debug(primes.size());
    int l, h;
    string p;
    cin >> l >> h >> p;
    l--, h--;
    int n = p.size(), ans = 0;

    while(l <= h) {
        string cur = to_string(primes[l]);
        int m = cur.size();
        bool fnd = false;
        for(int i = 0; i + n <= m; i++) {
            bool fnd2 = true;
            for(int j = 0; j < n; j++) {
                if(cur[(i + j)] != p[j]) {
                    fnd2 = false;
                    break;
                }
            }
            if(fnd2) {
                fnd = true;
                break;
            }
        }
        ans += fnd;
        l++;
    }

    cout << ans << "\n";



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

