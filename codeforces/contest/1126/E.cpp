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
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    auto check = [&](int c) {
        // can we do it in c split?
        int last_k = k + n + c * 2 - 1, split = 0, total = n;
        vector<int> copy = cnt;
        for(int i = n; i > 1 && total <= last_k; i--) {
            while(copy[i] > 0) {
                if(i > last_k) {
                    split++;
                    copy[(i + 1) / 2] += 2;
                    total++;
                } else {    
                    last_k--;
                    total--;
                }
                copy[i]--;
            }
        }
        if(total > last_k) {
            return false;
        }

        return c >= split;
    };

    int l = 0, r = n; 
    while(l < r) {
        int m = (l + r) / 2;
        if(check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << n + l * 2 << "\n";
}

int main() {
    FAST
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

