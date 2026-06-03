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

void solve() {
    int n;
    cin >> n;
    n -= 2;
    vector<vector<int> > a(n, vector<int> (3));
    vector<vector<int> > original_a(n, vector<int> (3));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
        original_a[i] = a[i];
        sort(a[i].begin(), a[i].end());
    }

    int root_ind = -1;
    unordered_map<int, unordered_set<int> > inds;
    for(int i = 0; i < n; i++) {
        // debug(a[i][0], a[i][1], a[i][2]);
        if((a[i][0] + a[i][1] + a[i][2] == n + 2) && root_ind == -1) {
            root_ind = i;
            continue;
        }

        if(a[i][0] + a[i][1] == a[i][2]) {
            // not center/root.
            inds[a[i][2]].insert(i);
        } else {
            cout << "No\n";
            return;
        }
    }

    if(root_ind == -1) {
        cout << "No\n";
        return;
    }

    vector<vector<int> > pos(n, vector<int> (3));

    function<bool(int, int, int)> dfs = [&](int cur, int l, int r) {
        if(cur == 1) return true;
        if(inds[cur].empty()) return false;

        int ind = *inds[cur].begin();
        inds[cur].erase(ind);
        int mid;
        if(original_a[ind][0] == cur) {
            pos[ind][0] = l;
            pos[ind][1] = r;
            pos[ind][2] = r - original_a[ind][1];
            mid = r - original_a[ind][1];
        } else if(original_a[ind][1] == cur) {
            pos[ind][1] = l;
            pos[ind][2] = r;
            pos[ind][0] = r - original_a[ind][2];
            mid = r - original_a[ind][2];
        } else {
            pos[ind][2] = l;
            pos[ind][0] = r;
            pos[ind][1] = r - original_a[ind][0];
            mid = r - original_a[ind][0];
        }
        // pos[ind][0] = l;
        // pos[ind][1] = l + x;
        // pos[ind][2] = r;
        return dfs(mid - l, l, mid) && dfs(r - mid, mid, r);
    };

    bool ans = true;
    int cur = 1;
    for(int i = 0; i < 3; i++) {
        pos[root_ind][i] = cur;
        int nxt = cur + original_a[root_ind][i];
        ans = (ans & dfs(original_a[root_ind][i], cur, cur + original_a[root_ind][i]));
        cur = nxt;
    }

    if(!ans) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cout << (pos[i][j] > n + 2 ? pos[i][j] - n - 2 : pos[i][j]) << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
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

