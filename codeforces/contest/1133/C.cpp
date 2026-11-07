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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) {
        cin >> x;

    }

    /*
    find min gap value
    at most 1 operation -> dp
    operation: reverse [l, r] then double every element.
    double every element -> gap in that range only increases so we need to check at the edge.
    kind of do binary search? 
    if max gap allowed is X, 
    how many operation do we need? 

    can[i] = 1 if |a[i] - a[i + 1]| > X
             0 if |a[i] - a[i + 1]| * 2 > X
             2 otherwise

    // we can have only one 1. 
    X = 3
    5 1 2 1 5 
    1 2 2 1
    5 2 4 2 5
    */

    auto check = [&](int X) -> bool {
        vector<int> can(n - 1);
        vector<int> pos;
        for(int i = 0; i < n - 1; i++) {
            int d = abs(a[i] - a[i + 1]);
            if(d > X) {
                can[i] = 1;
                pos.pb(i);
            } else if(d * 2 > X) {
                can[i] = 0;
            } else {
                can[i] = 2;
            }
        }

        if(pos.empty()) {
            return true;
        }

        if(pos.size() > 2) {
            return false;
        }

        auto check_border = [&](int l, int r) -> bool {
            if((l == 0 || abs(a[l - 1] - a[r] * 2) <= X) && (r == n - 1 || abs(a[r + 1] - a[l] * 2) <= X)) {
                return true;
            }
            return false;
        };

        if(pos.size() == 2) {
            for(int i = pos[0] + 1; i < pos[1]; i++) {
                if(can[i] == 0) {
                    return false;
                }
            }

            if(check_border(pos[0] + 1, pos[1])) {
                return true;
            }

            return false;
        }

        // we need to do operation on [l + 1 .. ?]
        for(int i = pos[0] + 1; i < n; i++) {
            int l = pos[0] + 1, r = i;

            if(check_border(l, r)) {
                return true;
            }

            if(i < n - 1 && can[i] == 0) {
                break;
            }
        }

        for(int i = pos[0]; i >= 0; i--) {
            int l = i, r = pos[0];
            if(check_border(l, r)) {
                return true;
            }

            if(i > 0 && can[i - 1] == 0) {
                break;
            }
        }

        return false;
    };

    int mx = 0;
    for(int i = 0; i < n - 1; i++) {
        mx = max(abs(a[i] - a[i + 1]), mx);
    }

    int l = 0, r = mx;
    while(l < r) {
        int m = (l + r) / 2;
        // debug(l, r, m);
        if(check(m)) {
            r = m;
        } else {
            l = m + 1;
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

