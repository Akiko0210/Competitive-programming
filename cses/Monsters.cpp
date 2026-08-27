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
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for(int i = 0; i < n; i++) {
        cin >> mat[i];
    }

    int startx, starty;
    vector<pii> monsters;
    vector<vector<pii> > prev(n, vector<pii> (m));
    vector<vector<bool> > monsterOccupied(n, vector<bool> (m, false)), myvis = monsterOccupied;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 'A') {
                startx = i;
                starty = j;
                myvis[i][j] = true;
            }
            if(mat[i][j] == 'M') {
                monsters.pb({i, j});
                monsterOccupied[i][j] = true;
            }
        }
    }

    auto is_exit = [&](int i, int j) {
        if(i == 0 || i == n - 1 || j == 0 || j == m - 1) 
            return true;
        return false;
    };

    auto is_valid = [&](int i, int j) {
        if(i < 0 || i >= n || j < 0 || j >= m || mat[i][j] == '#') 
            return false;
        return true;
    };

    if(is_exit(startx, starty)) {
        cout << "YES\n";
        return 0;
    }

    vector<pii> mypos = {{startx, starty}};

    pii moves[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    map<pii, char> movechar;
    movechar[moves[0]] = 'U';
    movechar[moves[1]] = 'D';
    movechar[moves[2]] = 'L';
    movechar[moves[3]] = 'R';

    while(!mypos.empty()) {
        vector<pii> nxt_monsters;
        for(auto [x, y] : monsters) {
            for(auto move : moves) {
                int nx = x + move.ff, ny = y + move.ss;
                if(!is_valid(nx, ny)) continue;

                if(!monsterOccupied[nx][ny]) {
                    nxt_monsters.pb({nx, ny});
                    monsterOccupied[nx][ny] = true;
                }
            }
        }
        vector<pii> nxt_mypos;
        for(auto [x, y] : mypos) {
            for(auto move : moves) {
                int nx = x + move.ff, ny = y + move.ss;
                if(!is_valid(nx, ny)) continue;

                if(!monsterOccupied[nx][ny] && !myvis[nx][ny]) {
                    nxt_mypos.pb({nx, ny});
                    myvis[nx][ny] = true;
                    prev[nx][ny] = {x, y};
                    if(is_exit(nx, ny)) {
                        pii cur = {nx, ny};
                        string dir = "";
                        while(cur != make_pair(startx, starty)) {
                            int dx = cur.ff - prev[cur.ff][cur.ss].ff;
                            int dy = cur.ss - prev[cur.ff][cur.ss].ss;
                            dir += movechar[{dx, dy}];
                            cur = prev[cur.ff][cur.ss];
                        }
                        cout << "YES\n";
                        cout << dir.size() << "\n";
                        reverse(dir.begin(), dir.end());
                        cout << dir << "\n";
                        return 0;
                    }
                }
            }
        }
        mypos = nxt_mypos;
        monsters = nxt_monsters;
    }

    cout << "NO\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

