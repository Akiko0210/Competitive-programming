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

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dx[] = {-1, 0, -1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1};

    auto iscross = [&] (int x, int y) {
        for(int i = 0; i < 5; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(a[nx][ny] != 'X') {
                return false;
            }
        }
        return true;
    };

    int ans = 0;
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - 1; j++) {
            ans += iscross(i, j);
        }
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

