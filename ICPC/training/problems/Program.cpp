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
    FAST
    /*
    basic solution:
    Q * K.

    for each query, (L, R):
    sum of i to K (R / X[i] + 1 - (L - 1) / X[i] + 1) if L > 0
    actually can do sieve? 
    */

    int n, k;
    cin >> n >> k;
    unordered_map<int, int> qty;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        qty[x]++;
    }

    int MAX = 1e6;
    vector<ll> sum(MAX + 1, 0);
    for(auto &[x, count] : qty) {
        for(int i = 0; i <= MAX; i += x) {
            sum[i] += count;
        }
    }

    for(int i = 1; i <= MAX; i++) {
        sum[i] += sum[i - 1];
    }

    int q;
    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        cout << sum[R] - (L > 0 ? sum[L - 1] : 0) << "\n";;
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

