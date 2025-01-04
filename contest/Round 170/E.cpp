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

const ll MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    int cnt = 0;
    set<pair<set<int>, set<int> > > ans;
    do {
        bool can = true;
        for(int i = 0; i < n / 2; i++) {
            if(a[i] < a[i + n / 2]) {
                can = false;
                break;
            }
        }

        if(can) {
            set<int> s, t;
            for(int i = 0; i < n; i++) {
                if(i < n / 2) s.insert(a[i]);
                else t.insert(a[i]);
            }
            ans.insert({s, t});
        }
    } while(next_permutation(a.begin(), a.end()));
    // for(auto el : ans) {
    //     for(auto x : el.first) {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    //     for(auto x : el.second) {
    //         cout << x << " ";
    //     }
    //     cout << "\n\n";
    // }
    debug(ans.size());
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

