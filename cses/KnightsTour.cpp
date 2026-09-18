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

/*
state = 64 bit int.
dp[state][last_pos] = true
dp[last_pos] = unordered_set of state where the knight can finish at last_pos;
*/

const ull MAX = UINT64_MAX;

vector<unordered_map<ull, int8_t> > can(64);
vector<vector<int> > G(64);

pii moves[] = {
    {-1, 2}, {1, 2}, 
    {-1, -2}, {1, -2},
    {-2, 1}, {-2, -1}, 
    {2, 1}, {2, -1}, 
};

int getpos(int lastpos, int i) {
    int r = lastpos / 8, c = lastpos % 8;
    int nr = r + moves[i].ff, nc = c + moves[i].ss;
    if(nr < 0 || nr > 7 || nc < 0 || nc > 7) {
        return -1; // invalid position
    }

    return nr * 8 + nc;
}

int cnt = 64;
vector<vector<int> > ans(8, vector<int> (8));

void paint(int pos) {
    int r = pos / 8, c = pos % 8;
    ans[r][c] = cnt--;
}

void print(ull state, int lastpos) {
    cout << lastpos / 8 << " " << lastpos % 8 << "\n";
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            int x = i * 8 + j;
            if(state & (1ULL << x)) {
                cout << (x == lastpos ? "S" : "x");
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool check(ull state, int lastpos) {
    if(state == MAX) {
        return true;
    }

    if(can[lastpos].find(state) != can[lastpos].end()) {
        if(can[lastpos][state] != -1) {
            return can[lastpos][state];
        }
        return false;
    }

    can[lastpos][state] = -1;

    vector<pii> next_move;

    for(int newpos : G[lastpos]) {
        if(state & (1ULL << newpos)) continue;

        int deg = 0;
        for(int x : G[newpos]) {
            if(state & (1ULL << x)) continue;

            deg++;
        }

        next_move.push_back({deg, newpos});

        // ll newstate = (state | (1ULL << newpos));
        // if(check(newstate, newpos)) {
        //     paint(newpos);
        //     can[lastpos][state] = true;
        //     return true;
        // }
    }

    sort(next_move.begin(), next_move.end());
    for(auto [deg, newpos] : next_move) {
        ll newstate = (state | (1ULL << newpos));
        if(check(newstate, newpos)) {
            paint(newpos);
            can[lastpos][state] = true;
            return true;
        }
    }

    return can[lastpos][state] = false;
}

int main() {
    int r, c;
    cin >> c >> r;
    r--, c--;
    for(int i = 0; i < 64; i++) {
        for(int j = 0; j < 8; j++) {
            int newpos = getpos(i, j);
            if(newpos != -1)
                G[i].pb(newpos);
        }
    }

    for(int i = 0; i < 64; i++) {
        sort(G[i].begin(), G[i].end(), [](int a, int b) {
            return G[a].size() < G[b].size();
        });
    }

    int lastpos = r * 8 + c;

    check((1ULL << lastpos), lastpos);
    paint(lastpos);
    for(auto row : ans) {
        for(int x : row) {
            cout << x << " ";
        }
        cout << "\n";
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

