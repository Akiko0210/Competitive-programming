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

const int N = 2e5;
vector<int> primes;

void sieve() {
    vector<bool> p(N + 1, true);
    for(int i = 2; i <= N; i++) {
        if(p[i]) {
            primes.pb(i);
            for(ll j = (ll)i * i; j <= N; j += i) {
                p[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    for(int x : a) {
        int p = *lower_bound(primes.begin(), primes.end(), x);
        cout << p << " ";
    }
    cout << "\n";

    /*
    The array can't have 2 even number that's greater than 2.
    we can always add 1 to a number
    we can make the whole array coprime.
    after we do a[i] += x, a[i] is not divisible by 
    any number that it was divisible before.

    
    
    */

}

int main() {
    sieve();
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

