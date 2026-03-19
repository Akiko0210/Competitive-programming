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

vector<vector<int> > G;
vector<int> val;

multiset<int> dfs(int cur) {
    if(G[cur].empty()) {
        multiset<int> res;
        res.insert(val[cur]);
        return res;
    }
    multiset<int> mx;
    for(int c : G[cur]) {
        multiset<int> temp = dfs(c);
        if(temp.size() > mx.size()) {
            swap(temp, mx);
        }
        mx.merge(temp);
    }


    auto it = mx.lower_bound(val[cur]);
    if(it != mx.end()) {
        mx.erase(it);
    }
    mx.insert(val[cur]);

    return mx;
}

int main() {
    int n;
    cin >> n;
    val.resize(n + 1);
    G.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> val[i];
        int p;
        cin >> p;
        G[p].pb(i);
    }

    multiset<int> ans = dfs(1);

    cout << ans.size() << "\n";


    return 0;
}
