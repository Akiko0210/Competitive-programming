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

int main() {
    int n, m, sx = 0, sy = 0, ex = 0, ey = 0;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if(a[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }

    auto validPos = [&] (int x, int y) {
        if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
            return false;
        }
        return true;
    };

    int x[] = {1, 0, -1, 0};
    int y[] = {0, -1, 0, 1};
    string dirs = "DLUR";

    vector<vector<int> > cost(n, vector<int> (m, INF));
    vector<vector<pii> > prev(n, vector<pii> (m));
    vector<vector<char> > prevChar(n, vector<char> (m));
    cost[sx][sy] = -1;
    queue<pair<pii, pair<pii, char> > > q;
    q.push({{sx, sy}, {{sx, sy}, 'D'}});

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        pii curpos = cur.ff, prevpos = cur.ss.ff;
        char dir = cur.ss.ss;
        if(curpos != prevpos && (!validPos(curpos.ff, curpos.ss) || cost[curpos.ff][curpos.ss] <= cost[prevpos.ff][prevpos.ss] + 1)) 
            continue;
        
        cost[curpos.ff][curpos.ss] = cost[prevpos.ff][prevpos.ss] + 1;
        prev[curpos.ff][curpos.ss] = prevpos;
        prevChar[curpos.ff][curpos.ss] = dir;
        for(int i = 0; i < 4; i++) {
            int nx = curpos.ff + x[i], ny = curpos.ss + y[i];
            q.push({{nx, ny}, {curpos, dirs[i]}});
        }
    }
    if(cost[ex][ey] == INF) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";

    cout << cost[ex][ey] << "\n";
    string path = "";
    // debug(sx, sy);
    while(ex != sx || ey != sy) {
        // debug(ex, ey);
        path += prevChar[ex][ey];
        int tx = ex;
        ex = prev[ex][ey].ff;
        ey = prev[tx][ey].ss;
        // debug("after", ex, ey, sx, sy);
    }
    reverse(path.begin(), path.end());
    cout << path << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

