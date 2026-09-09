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
    int n;
    cin >> n;
    if(n == 1) {
        cout << "01\n";
        return 0;
    }
    int max_mask = (1 << (n - 1));
    vector<vector<int> > G(max_mask);

    for(int cur = 0; cur < max_mask; cur++) {
        int addone = ((cur << 1) + 1) % max_mask;
        int addzero = (cur << 1) % max_mask;
        G[cur].pb(addone);
        G[cur].pb(addzero);
    }

    vector<int> tour;
    function<void(int)> dfs = [&](int cur) {
        while(!G[cur].empty()) {
            int nxt = G[cur].back();
            G[cur].pop_back();
            dfs(nxt);
        }

        tour.pb(cur);
    };

    dfs(0);
    reverse(tour.begin(), tour.end());
    for(int i = 0; i < n - 2; i++) {
        cout << "0";
    }

    for(int x : tour) {
        cout << x % 2;
    }
    cout << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

