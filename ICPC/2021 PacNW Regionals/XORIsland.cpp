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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    int maxmask = (1 << n);
    vector<bool> bad(maxmask, false);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if((a[i] ^ a[j] ^ a[k]) == 0) {
                    int mask = (1 << i) | (1 << j) | (1 << k);
                    // debug(mask, i, j, k);
                    bad[mask] = true;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int x = 0; x < maxmask; x++) {
            if(x & (1 << i)) {
                bad[x] = bad[x] | bad[x ^ (1 << i)];
            }
        }
    }

    int ans = 0;
    for(int x = 0; x < maxmask; x++) {
        if(!bad[x]) {
            ans = max(ans, __builtin_popcount(x));
        }
    }

    cout << n - ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

