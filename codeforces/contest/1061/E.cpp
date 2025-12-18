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
    /*
    If there's i < j s.t p[j] - p[i] >= g
    sorted pre_array. 
    f(g, i) has 4 states:
    - 0, 1, 2, more than 2. 
    When removing a[i], we're ignoring, f(g, i) and subtracting 1 from f(g, j) such that f(g, j) included i. 
    */ 
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto insert = [&](int x, vector<int>& cur) {
        cur.pb(x);
        for(int i = cur.size() - 1; i > 0; i--) {
            if(a[cur[i]] < a[cur[i - 1]]) {
                swap(cur[i], cur[i - 1]);
            }
        }
        if(cur.size() > 3) cur.pop_back();
    };

    int l = -1e9, r = 1e9;
    while(l < r) {
        int g = l + (r - l + 1) / 2;
        vector<int> lowest, f(n, 0);
        vector<vector<int> > use(n);
        int cnt2 = 0;
        for(int i = 0; i < n; i++) {
            for(int low : lowest) {
                if(a[i] - a[low] >= g) {
                    use[low].pb(i);
                    use[i].pb(low);
                    f[i]++;
                    f[low]++;
                }
            }
            insert(i, lowest);
        }

        for(int i = 0; i < n; i++) {

            cnt2 += (f[i] >= 2);
        }
        // debug(g, cnt2);
        bool can = false;
        for(int i = 0; i < n; i++) {
            // if we deleted i?
            cnt2 -= (f[i] >= 2);
            for(int x : use[i]) {
                cnt2 -= (f[x] == 2);
            }

            if(cnt2 == 0) {
                // debug(i, "can");
                r = g - 1;
                can = true;
                break;
            }

            cnt2 += (f[i] >= 2);
            for(int x : use[i]) {
                cnt2 += (f[x] == 2);
            }
        }
        if(!can) {
            l = g;
        }
    }
    cout << l << "\n";
}

int main() {
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

