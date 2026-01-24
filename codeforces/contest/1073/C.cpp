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
    string s;
    cin >> n >> s;
    vector<vector<int> > pos(2);
    for(int i = 0; i < n; i++) {
        pos[s[i] - '0'].pb(i);
    }

    vector<int> ans1, ans2;
    for(int x : pos[1]) {
        if(pos[0].empty()) break;
        if(x < pos[0].back()) {
            ans1.pb(x);
            ans2.pb(pos[0].back());
            pos[0].pop_back();
        } else {
            break;
        }
    }

    while(!ans2.empty()) {
        ans1.pb(ans2.back());
        ans2.pop_back();
    }

    if(ans1.empty()) {
        cout << "Bob\n";
        return;
    }


    cout << "Alice\n";
    cout << ans1.size() << "\n";
    for(int x : ans1) {
        cout << x + 1 << " ";
    }
    cout << "\n";
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

