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

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int N = 400;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }


    vector<vector<bool> > vis(N, vector<bool> (N, false));
    vector<vector<int> > cur;
    cur.pb({200, 200, 0});

    auto prev = [] (int x) {
        return (x + 7) % 8;
    };

    auto next = [] (int x) {
        return (x + 1) % 8;
    };

    for(int i = 0; i < n; i++) {
        set<vector<int> > s;
        for(auto el : cur) {
            for(int j = 1; j <= t[i]; j++) {
                el[0] += dx[el[2]];
                el[1] += dy[el[2]];
                // int x = el[0] + dx[el[2]] * j;
                // int y = el[1] + dy[el[2]] * j;
                vis[el[0]][el[1]] = 1;
            }
            s.insert({el[0], el[1], prev(el[2])});
            s.insert({el[0], el[1], next(el[2])});
        }
        cur.clear();
        for(auto el : s) {
            cur.pb(el);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans += vis[i][j];
        }
    }

    cout << ans << "\n";
    
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

