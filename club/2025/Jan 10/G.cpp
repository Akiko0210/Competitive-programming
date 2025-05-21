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

void solve() {
}

int main() {
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector<int> a(k);
    int cnt = 0, sum = 0;
    for(int i = 0; i < k; i++)  {
        cin >> a[i];
        sum += a[i];
        if(a[i] < y) {
            cnt++;
        }
    }

    int rem = n - k, extra = min(n / 2 - cnt, rem);
    if(extra < 0) {
        cout << "-1\n";
        return 0;
    }
    
    sum += extra + (rem - extra) * y;
    if(sum <= x) {
        for(int i = 0; i < rem; i++) {
            cout << (i < extra ? 1 : y) << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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

