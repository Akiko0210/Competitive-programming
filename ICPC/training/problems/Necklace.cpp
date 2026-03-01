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
}

int main() {
    int n;
    cin >> n;

    while (n != 0) {
        string s, t;
        cin >> s >> t;
        int ans = INF;
        for(int i = 0; i < n; i++) {
            int l = i, r = (i + 1) % n;
            // l goes to the left
            // r goes to the right.
            int cntG = 0, cntS = 0, mx = 0;
            for(int j = 0; j < n; j++) {
                if(s[r] == 'G' && cntG > 0) {
                    cntG--;
                    r = (r + 1) % n;
                    continue;
                }

                if(s[l] == 'S' && cntS > 0) {
                    cntS--;
                    l = (l - 1 + n) % n;
                    continue;
                }
                
                if(t[j] == s[l]) {
                    l = (l - 1 + n) % n;
                    continue;
                } 
                if(t[j] == s[r]) {
                    r = (r + 1) % n;
                    continue;
                }


                if(t[j] == 'G') {
                    cntG++;
                } else {
                    cntS++;
                }

                mx = max(mx, cntG + cntS);
            }
            ans = min(ans, mx);
        }
        cout << ans << "\n";
        cin >> n;
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

