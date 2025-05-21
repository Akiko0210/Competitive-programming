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
const int N = 2e5 + 1;

int n, q;
int px[N], py[N], sx[N], sy[N];

int main() {
    FAST
    string s;
    cin >> n >> q >> s;
    unordered_map<long long, vector<int> > sm, pm;

    for(int i = 0; i < n; i++) {
        if(s[i] == 'R' || s[i] == 'L')
            px[i] += (s[i] == 'R' ? 1 : -1);
        else
            py[i] += (s[i] == 'U' ? 1 : -1);
        

        if(i > 0) {
            px[i] += px[i - 1];
            py[i] += py[i - 1];
        }

        pm[px[i] * N + py[i]].pb(i);
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'R' || s[i] == 'L')
            sx[i] += (s[i] == 'R' ? 1 : -1);
        else
            sy[i] += (s[i] == 'U' ? 1 : -1);
        
        if(i < n - 1) {
            sx[i] += sx[i + 1];
            sy[i] += sy[i + 1];
        }

        sm[sx[i] * N + sy[i]].pb(i);
    }
    for(auto &el : sm) {
        reverse(el.second.begin(), el.second.end());
    }

    auto search_between = [&] (int x, int y, int l, int r) -> bool {
        if(l > 0) {
            x -= px[l - 1];
            y -= py[l - 1];
        }
        if(r < n - 1) {
            x += sx[r + 1];
            y += sy[r + 1];
        }
        // debug(x, y);
        auto it = lower_bound(sm[x * N + y].begin(), sm[x * N + y].end(), l);
        if(it == sm[x * N + y].end()) {
            return false;
        }
        // cout << "here\n";
        // debug("here", *it <= r);
        return *it <= r;
    };

    auto search_front = [&] (int x, int y, int l) {
        int ind = lower_bound(pm[x * N + y].begin(), pm[x * N + y].end(), l) - pm[x * N + y].begin();
        ind--;
        // debug("here", ind >= 0);
        return ind >= 0;
    };

    auto search_back = [&] (int x, int y, int r) {
        auto it = upper_bound(pm[x * N + y].begin(), pm[x * N + y].end(), r);
        // debug("here", it != pm[x * N + y].end());
        return it != pm[x * N + y].end();
    };

    while(q--) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        if(x == 0 && y == 0) {
            cout << "YES\n";
            continue;
        }
        l--, r--;

        if(search_between(x, y, l, r) || search_front(x, y, l) || search_back(x, y, r)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
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

