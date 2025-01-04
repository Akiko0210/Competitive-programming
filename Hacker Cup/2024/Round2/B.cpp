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

map<vector<string>, vector<int> > m;

bool check_v (vector<string>& grid, int r, int c) {
    char p = grid[r][c];
    for(int i = 0; i < 4; i++) {
        if(r + i >= 6 || grid[r + i][c] != p) return false;
    }

    return true;
}

bool check_h (vector<string>& grid, int r, int c) {
    char p = grid[r][c];
    for(int i = 0; i < 4; i++) {
        if(c + i >= 7 || grid[r][c + i] != p) return false;
    }

    return true;
}

bool check_d1 (vector<string>& grid, int r, int c) {
    char p = grid[r][c];
    for(int i = 0; i < 4; i++) {
        if(c + i >= 7 || r + i >= 6 || grid[r + i][c + i] != p) return false;
    }

    return true;
}

bool check_d2 (vector<string>& grid, int r, int c) {
    char p = grid[r][c];
    for(int i = 0; i < 4; i++) {
        if(c - i < 0 || r + i >= 6 || grid[r + i][c - i] != p) return false;
    }

    return true;
}

int compare(vector<pii> a, vector<pii> b) {
    bool isalow = true;
    for(int i = 0; i < 4; i++) {
        if(a[i].ss != b[i].ss) return -1;

        if(a[i].ff <= b[i].ff) {
            isalow = false;
            break;
        }
    }

    if(isalow) {
        return 0;
    }

    bool isblow = true;
    for(int i = 0; i < 4; i++) {
        if(a[i].ss != b[i].ss) return -1;

        if(a[i].ff >= b[i].ff) {
            isblow = false;
            break;
        }
    }

    if(isblow) {
        return 1;
    }

    return -1;
}

void solve() {
    vector<string> grid(6);
    for(int i = 0; i < 6; i++) {
        cin >> grid[i];
    }
    vector<vector<pii> > wins;
    for(int r = 0; r < 6; r++) {
        for(int c = 0; c < 7; c++) {
            if(check_v(grid, r, c)) {
                vector<pii> cur;
                for(int i = 0; i < 4; i++) {
                    // if(r + i >= 6 || grid[r + i][c] != p) return false;
                    cur.pb({r + i, c});
                }
                wins.pb(cur);
            }

            if(check_h(grid, r, c)) {
                vector<pii> cur;
                for(int i = 0; i < 4; i++) {
                    // if(c + i >= 7 || grid[r][c + i] != p) return false;
                    cur.pb({r, c + i});
                }
                wins.pb(cur);
            }

            if(check_d1(grid, r, c)) {
                vector<pii> cur;
                for(int i = 0; i < 4; i++) {
                    // if(c + i >= 7 || r + i >= 6 || grid[r + i][c + i] != p) return false;
                    cur.pb({r + i, c + i});
                }
                wins.pb(cur);
            }

            if(check_d2(grid, r, c)) {
                vector<pii> cur;
                for(int i = 0; i < 4; i++) {
                    // if(c - i < 0 || r + i >= 6 || grid[r + i][c - i] != p) return false;
                    cur.pb({r + i, c - i});
                }
                wins.pb(cur);
            }
        }
    }

    int n = wins.size();
    vector<bool> valid(n, true);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int res = compare(wins[i], wins[j]);
            if(res == -1) {
                continue;
            }

            if(res == 0) {
                valid[j] = false;
            } else {
                valid[i] = false;
            }
        }
    }

    set<char> poswins;
    for(int i = 0; i < n; i++) {
        if(valid[i]) {
            // for(auto el : wins[i]) {
            //     cout << el.ff << " " << el.ss << "\n";
            // }
            // cout << "\nare winning locations\n";
            poswins.insert(grid[wins[i][0].ff][wins[i][0].ss]);
        }
    }

    if(poswins.empty()) {
        cout << "0\n";
        return;
    }

    if(poswins.size() == 2) {
        cout << "?\n";
        return;
    }

    cout << (*poswins.begin()) << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for(int _ = 1; _ <= t; _++) {
        cout << "Case #" << _ << ": ";
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

