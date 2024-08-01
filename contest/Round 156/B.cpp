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

double dis(pii a, pii b) {
    double ans = sqrt((a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss));
    return ans;
}

void solve() {
    vector<pii> p(3);
    vector<double> to_O(2);
    vector<double> to_P(2);
    for(int i = 0; i < 3; i++) {
        cin >> p[i].ff >> p[i].ss;
    }
    for(int i = 0; i < 2; i++) {
        to_O[i] = dis(p[i + 1], {0, 0});
        to_P[i] = dis(p[i + 1], p[0]);
    }
    // 1 can wrap everything.
    double ans = min(max(to_O[0], to_P[0]), max(to_O[1], to_P[1]));
    // 2 wrap together.
    double connect_dis = dis(p[1], p[2]) / 2;
    ans = min(ans, max(connect_dis, max(min(to_O[0], to_O[1]), min(to_P[0], to_P[1]))));
    
    cout << fixed << setprecision(10) << ans << "\n";


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
