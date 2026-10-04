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

// struct Segtree{
//     int n;
//     vector<unordered_set<int> > stree;

//     Segtree(int n) {
//         stree.resize(n * 4);
//     }

//     void propagate(int i) {
//         int x = i * 2 + 1, y = i * 2 + 2;
//         // debug(i);
//         while(!stree[i].empty()) {
//             int val = *stree[i].begin();
//             stree[x].insert(val);
//             stree[y].insert(val);
//             stree[i].erase(stree[i].begin());
//         }
//         // debug("done");
//     }

//     void update(int i, int L, int R, int l, int r, int val) {
//         if(l <= L && R <= r) {
//             stree[i].insert(val);
//             return;
//         }
//         propagate(i);
//         int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
//         if(l <= M) {
//             update(x, L, M, l, r, val);
//         }

//         if(r > M) {
//             update(y, M + 1, R, l, r, val);
//         }
//     }

//     int query(int i, int L, int R, int ind) {
//         if(L == R) {
//             // cout << "at ind " << ind << ":\n";
//             // for(int x : stree[i]) {
//             //     cout << x << " ";
//             // }
//             // cout << "\n";
//             return stree[i].size();
//         }
//         propagate(i);
//         int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
//         if(ind <= M) {
//             return query(x, L, M, ind);
//         }

//         return query(y, M + 1, R, ind);
//     }
// };

int main() {
    int n, q;
    cin >> n >> q;
    // Segtree stree(n);
    unordered_map<int, vector<pii> > ranges;

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        ranges[x].pb({l, r});
        // stree.update(0, 0, n - 1, l, r, x);
    }

    vector<int> line(n + 1, 0);

    for(auto &[k, p] : ranges) {
        sort(p.begin(), p.end());
        vector<pii> updated;
        for(auto &[l, r] : p) {
            if(updated.empty() || updated.back().ss < l - 1) updated.pb({l, r});
            else updated.back().ss = max(updated.back().ss, r);
        }

        for(auto &[l, r] : updated) {
            line[l]++;
            line[r + 1]--;
        }
    }

    for(int i = 1; i <= n; i++) {
        line[i] += line[i - 1];
    }

    for(int i = 0; i < n; i++) {
        cout << line[i] << " ";
    }
    cout << "\n";

    // cout << "done\n";

    // for(int i = 0; i < n; i++) {
    //     cout << stree.query(0, 0, n - 1, i) << " ";
    // }
    // cout << "\n";

    /*


    
    */


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

