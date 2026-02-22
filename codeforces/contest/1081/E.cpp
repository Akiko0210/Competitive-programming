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
    vector<int> a(n), b(n);
    vector<unordered_set<int> > inds(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        // inds[a[i]].insert(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        // inds[b[i]].insert(i);
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) continue;
        
        inds[a[i]].insert(i);
        inds[b[i]].insert(i);
    }

    for(int i = 0; i <= n; i++) {
        if(inds[i].size() % 2 == 1) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(inds[a[i]].find(i) == inds[a[i]].end()) continue;

        int start = a[i], next = b[i];
        inds[a[i]].erase(i);
        inds[b[i]].erase(i);
        while(next != start) {
            int ind = *inds[next].begin();
            if(a[ind] != next) {
                swap(a[ind], b[ind]);
                ans.pb(ind);
            }
            next = b[ind];
            inds[a[ind]].erase(ind);
            inds[b[ind]].erase(ind);
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans) {
        cout << x + 1 << " ";
    }
    cout << "\n";

    





}

int main() {
    FAST
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

