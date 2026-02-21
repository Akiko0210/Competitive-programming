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
const int N = 431;

vector<int> primes;
vector<bool> p(N + 1, true);

void sieve() {
    for(int i = 2; i <= N; i++) {
        if(p[i]) {
            primes.pb(i);
            for(int j = i * i; j <= N; j += i) {
                p[j] = false;
            }
        }
    }
}

void solve(int a, int b) {
    vector<int> cnt(primes.size(), 0);
    // (b + 1 -> a) / (1 -> a - b)
    for(int i = b + 1; i <= a; i++) {
        int temp = i;
        for(int j = 0; j < primes.size(); j++) {
            if(primes[j] > temp) break;

            while(temp % primes[j] == 0) {
                cnt[j]++;
                temp /= primes[j];
            }
        }
    }
    for(int i = 1; i <= a - b; i++) {
        int temp = i;
        for(int j = 0; j < primes.size(); j++) {
            if(primes[j] > temp) break;

            while(temp % primes[j] == 0) {
                cnt[j]--;
                temp /= primes[j];
            }
        }
    }
    ull ans = 1;
    for(int x : cnt) {
        ans *= (x + 1);
    }
    cout << ans << "\n";
}

int main() {
    sieve();
    debug(primes.size());
    int a, b, cnt = 0;

    while(cin >> b) {
        cnt++;
        if(cnt == 1) {
            a = b;
        } else {
            cnt = 0;

            solve(a, b);
        }
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

