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
    int n, s_sum = 0, m_sum = 0, l_sum = 0;
    int s_size = 6, m_size = 8, l_size = 12;
    cin >> n;
    for(int i = 0; i < n; i++) {
        char c;
        int cnt;
        cin >> c >> cnt;
        if(c == 'S') {
            s_sum += cnt;
        } else if(c == 'M') {
            m_sum += cnt;
        } else {
            l_sum += cnt;
        }
    }

    int ans = s_sum / s_size + (s_sum % s_size > 0) +
        m_sum / m_size + (m_sum % m_size > 0) +
        l_sum / l_size + (l_sum % l_size > 0);
    cout << ans << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

