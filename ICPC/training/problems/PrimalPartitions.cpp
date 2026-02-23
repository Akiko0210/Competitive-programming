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

const int N = 1e3;
vector<int> primes;
vector<bool> p(N, true);

void sieve() {
    for(ll i = 2; i <= N; i++) {
        if(p[i]) {
            primes.pb(i);
            for(ll j = i * i; j <= N; j += i) {
                p[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    // debug(primes.size());
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 1e6;
    vector<vector<int> > factors(n);
    for(int i = 0; i < n; i++) {
        int temp = a[i];
        for(int x : primes) {
            if(x > temp) break;
            int cnt = 0;
            while(temp % x == 0) {
                temp /= x;
                cnt++;
            }
            if(cnt > 0) {
                factors[i].pb(x);
            }
        }
        if(temp > 1) {
            factors[i].pb(temp);
        }
        r = min(r, factors[i].back());
        // cout << a[i] << ": ";
        // for(int x : factors[i]) {
        //     cout << x << " ";
        // }
        // cout << "\n";
    }

    while(l < r) {
        // debug(l, r);
        int m = (l + r + 1) / 2, cnt = 1;
        vector<int> f = factors[0];
        for(int i = 1; i < n; i++) {
            // debug(i);
            vector<int> next;
            int ind1 = 0, ind2 = 0;
            while(ind1 < f.size() && ind2 < factors[i].size()) {
                if(f[ind1] == factors[i][ind2]) {
                    next.pb(f[ind1]);
                    ind1++;
                    ind2++;
                    continue;
                }
                if(f[ind1] < factors[i][ind2]) {
                    ind1++;
                } else {
                    ind2++;
                }
            }
            if(next.empty() || next.back() < m) {
                cnt++;
                f = factors[i];
            } else {
                f = next;
            }
        }

        if(cnt <= k) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

