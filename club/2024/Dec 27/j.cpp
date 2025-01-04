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
    int n, m;
    cin >> n >> m;
    vector<int> w(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        set<int> s;
        for(int j = 0; j < m; j++) {
            if(b[j] == i) {
                for(int x : s) {
                    ans += w[x - 1];
                }
                s.clear();
            } else {
                s.insert(b[j]);
            }
        }
    }

    // 5 + 4 + 3

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

