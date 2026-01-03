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

char next(char c) {
    if(c == 'r') return 'g';
    if(c == 'g') return 'b';
    return 'r';
}

char prev(char c) {
    if(c == 'r') return 'b';
    if(c == 'g') return 'r';
    return 'g';
}

void first() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[v].pb(u);
        G[u].pb(v);
    }

    // bfs
    vector<int> dis(n, -1);
    queue<int> q;
    string s(n, ' ');
    q.push(0);
    dis[0] = 0;
    s[0] = 'r';
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int x : G[cur]) {
            if(dis[x] == -1) {
                dis[x] = dis[cur] + 1;
                s[x] = next(s[cur]);
                q.push(x);
            }
        }
    }

    cout << s << "\n";
}

void second() {
    int q;
    cin >> q;
    while(q--) {
        int d;
        string color;
        cin >> d >> color;
        set<char> pos = {'r', 'b', 'g'};
        for(char c : color) {
            pos.erase(c);
        }

        char vcolor;
        if(pos.size() == 2) {
            vcolor = next(color[0]);
        } else {
            vcolor = *pos.begin();
        }
        char togo = prev(vcolor);
        for(int i = 0; i < d; i++) {
            if(color[i] == togo) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
}

int main() {
    string flag;
    cin >> flag;
    int t = 1;
    cin >> t;
    while(t--) {
        if(flag == "first") first();
        else second();
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

