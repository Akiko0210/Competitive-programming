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
    int n;
    cin >> n;
    vector<pii> range(n);
    vector<int> p(n), ind(n);
    iota(ind.begin(), ind.end(), 0);
    set<int> k;
    for(int i = 0; i < n; i++) {
        cin >> range[i].ff >> range[i].ss >> p[i];
        // k.insert(range[i].ff);
        k.insert(range[i].ss);
    }
    vector<int> keys;
    for(int x : k) {
        keys.pb(x);
    }

    // sort(keys.begin(), keys.end());
    sort(ind.begin(), ind.end(), [&](int i, int j) {
        if(range[i].ss > range[j].ss) {
            return 0;
        }
        return 1;
    });

    unordered_map<int, ll> umap;
    for(int i = 0; i < n; i++) {
        int start = range[ind[i]].ff, end = range[ind[i]].ss;
        int j = lower_bound(keys.begin(), keys.end(), start) - keys.begin();
        j--;
        if(j >= 0) {
            umap[end] = max(umap[end], umap[keys[j]] + p[ind[i]]);
        } else {
            umap[end] = max(umap[end], (ll)p[ind[i]]);
        }
        j = lower_bound(keys.begin(), keys.end(), end) - keys.begin();
        j--;
        if(j >= 0)
            umap[end] = max(umap[end], umap[keys[j]]);
        // debug(i, start, end, umap[end]);
    }

    cout << umap[keys[keys.size() - 1]] << "\n";





    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

