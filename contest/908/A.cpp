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
    int n, l1 = 0;
    string s;
    cin >> n >> s;
    for(char c: s) {
        if(c == s[n - 1]) l1++;
    }

    for(int i = 1; i <= n; i++) {
        if(l1 % i == 0) {
            int cnt1 = 0, cur1 = 0, cur2 = 0, cnt2 = 0, x = i, y = l1 / x;
            // debug(x, y);
            for(int j = 0; j < n; j++) {
                // debug(s[j], s[n - 1]);
                if(s[j] == s[n - 1]) 
                    cur1++;
                else 
                    cur2++;

                if(cur2 == x) {
                    cur2 = 0;
                    cnt2++;
                    cur1 = 0;
                } 
                if(cur1 == x) {
                    cur1 = 0;
                    cur2 = 0;
                    cnt1++;
                }
                if(cnt1 == y && cnt2 < y) {
                    cout << s[n - 1] << "\n";
                    return;
                }
            }
        }
    }
    cout << "?\n";

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

