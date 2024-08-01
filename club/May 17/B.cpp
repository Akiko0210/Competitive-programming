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
    ifstream cin ("speeding.in");
    ofstream cout ("speeding.out");

    int n, m;
    cin >> n >> m;
    int prev = 0;
    vector<int> limit(101);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for(int j = 0; j < x; j++) {
            limit[prev + j] = y;
        }
        prev += x;
    }

    prev = 0;
    int ans = 0;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        for(int j = 0; j < x; j++) {
            ans = max(ans, max(0, y - limit[prev + j]));
        }
        prev += x;
    }
    cout << ans << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

