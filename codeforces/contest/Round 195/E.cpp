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
    ll n;
    string s;
    cin >> n >> s;

    auto calc = [&](string s1, string s2) {
        vector<int> start2025(4, -1), start2026(4, -1);
    
        vector<ll> sweep(n + 1, 0), mult(n + 1, 0), sub(n + 1, 0);
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) {
                if(s1[j] == s[i]) {
                    start2025[j] = (j == 0 ? i : start2025[j - 1]);
                }
                
                if(s2[j] == s[i]) {
                    start2026[j] = (j == 0 ? i : start2026[j - 1]);
                }
            }
            int A = start2026[3], B = start2025[3];
            ll bad = max(B - A, 0);
            if(bad > 0) {
                sweep[start2025[3]] += bad;
                sweep[i + 1] -= bad;

                mult[A + 1]++;
                mult[B]--;
                sub[A + 1] += A;
                sub[B] -= A;
            }
        }
    
        vector<ll> ans(n);
        ll cursweep = 0, curmult = 0, cursub = 0;
        for(int i = 0; i < n; i++) {
            cursweep += sweep[i];
            curmult += mult[i];
            cursub += sub[i];

            ans[i] = i * curmult - cursub + cursweep;
        }

        return ans;
    };

    vector<ll> pre = calc("2025", "2026");
    for(int i = 0; i < n; i++) {
        ll total = (ll)(i + 1) * (n - i);
        total -= pre[i];
        cout << total << " ";
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

