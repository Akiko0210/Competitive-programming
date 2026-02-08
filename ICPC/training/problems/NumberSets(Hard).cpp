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
const int N = 1e6;

vector<int> primes;
vector<bool> p;

void sieve() {
    for(int i = 2; i < N; i++) {
        if(p[i]) {
            primes.pb(i);
            if(i < 1000) {
                for(int j = i * i; j <= N; j += i) {
                    p[j] = false;
                }
            }
        }
    }
}

struct DSU {
    int total;
    vector<int> par, size;
    DSU(int n) {
        total = n;
        par.resize(n);
        size.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b) {
        int para = find(a), parb = find(b);
        if(para == parb) {
            return;
        }
        total--;
        // debug(total);
        if(size[para] > size[parb]) {
            swap(para, parb);
        }

        par[para] = parb;
        size[parb] += size[para];
        size[para] = 0;
    }

    int sets() {
        return total;
    }
};

void print (int t, int ans) {
    cout << "Case #" << t << ": " << ans << "\n";
}

int main() {
    p.resize(N + 1, true);
    sieve();

    int C;
    cin >> C;
    for(int _ = 1; _ <= C; _++) {
        ll L, R, P;
        cin >> L >> R >> P;
        int n = R - L + 1;
        if(P > N) {
            print(_, n);
            continue;
        }
        DSU dsu(n);
        int ind = lower_bound(primes.begin(), primes.end(), P) - primes.begin();
        for(; ind < primes.size() && primes[ind] <= R; ind++) {
            int x = primes[ind];
            // debug(x);
            ll start = ((L - 1) / x + 1) * x;
            for(ll i = start; i <= R; i += x) {
                // debug(i, start);
                dsu.merge(i - L, start - L);
            }
        }
        print(_, (int)dsu.sets());
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