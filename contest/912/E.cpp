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

const ll MOD = 1e9 + 7;

void solve() {
    // even - first
    // odd - second
    string players[2] = {"First", "Second"};
    /*
    (sx - x[0]) + (x[0] - x[1]) .... (x[n - 1] - x[n]) = sx - x[n];
    (sy - y[0]) + (y[0] - y[1]) .... (y[n - 1] - y[n]) = sy - y[n];

    sum = sx + sy - x[n] - y[n];
    */


    int n, sx, sy;
    cin >> n >> sx >> sy;
    vector<vector<int> > nums(2);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nums[(x + y) % 2].pb(i + 1);
    }

    // debug(nums[0].size(), nums[1].size());
    // for(int x : nums[0]) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    // for(int x : nums[1]) {
    //     cout << x << " ";
    // }
    // cout << "\n";

    vector<bool> vis(n + 1, 0);

    auto play = [&](vector<int>& a, vector<int>& b) {
        while(b.size() > 0) {
            while(b.size() > 0 && vis[b.back()]) {
                b.pop_back();
            }

            if(b.size() > 0) {
                cout << b.back() << "\n";
                b.pop_back();
                n--;
                if(n > 0) {
                    int x;
                    cin >> x;
                    vis[x] = 1;
                    n--;
                }
            }
        }

        while(a.size() > 0) {
            while(a.size() > 0 && vis[a.back()]) {
                a.pop_back();
            }

            if(a.size() > 0) {
                cout << a.back() << "\n";
                a.pop_back();
                n--;
                if(n > 0) {
                    int x;
                    cin >> x;
                    vis[x] = 1;
                    n--;
                }
            }
        }
    };

    if(nums[(sx + sy) % 2].size() >= nums[1 - (sx + sy) % 2].size()) {
        cout << "First\n";
        play(nums[(sx + sy) % 2], nums[1 - (sx + sy) % 2]);
    } else {
        cout << "Second\n";
        int x;
        cin >> x;
        vis[x] = 1;
        n--;
        play(nums[1 - (sx + sy) % 2], nums[(sx + sy) % 2]);
    }

    // cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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

