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

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    // players, throws, begin
    vector<bool> have_ball(n, 0), next(n, 0);
    have_ball[x - 1] = 1;
    for(int i = 0; i < m; i++) {
        int r;
        char c;
        cin >> r >> c;
        for(int i = 0; i < n; i++) {
            if(have_ball[i]) {
                if(c == '0')
                    next[(i + r) % n] = 1;
                if(c == '1')
                    next[(i - r + n) %  n] = 1;
                if(c == '?') {
                    next[(i + r) % n] = 1;
                    next[(i - r + n) % n] = 1;
                } 

            }
        }
        have_ball= next;
        next = vector<bool> (n, 0);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(have_ball[i]) ans.pb(i);
    }
    cout << ans.size() << "\n";
    for(int x  : ans) {
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

 