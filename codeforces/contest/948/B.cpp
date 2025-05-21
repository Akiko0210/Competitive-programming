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
    long long n;
    cin >> n;
    int cnt = 0;
    vector<int> ans(32, 0);
    for(int i = 0; i < 32; i++) {
        if(n & (1LL << i)) {
            ans[i] = 1;
        }
    }

    int carry = 0, l = 0;
    // for(int x : ans) {
    //     cout << x << " ";
    // }

    for(int i = 0; i < 32; i++) {
        if(ans[i]) {
            l++;
            if(carry) {
                ans[i] = 0;
                continue;
            }

            carry = 1;
            ans[i] = -1;

        } else {
            if(carry) {
                if(l > 1) {
                    ans[i] = -1;
                    l = 1;
                } else {
                    ans[i - 1] = 1;
                    carry = 0;
                    l = 0;
                }
            }
        }
    }
    cout << 32 << "\n";
    // for(int i = 0; i + 1 < 31; i++) {
    //     if(ans[i] == 1 && ans[i + 1] == -1) {
    //         ans[i] = -1;
    //         ans[i + 1] = 0;
    //     }
    // }

    for(int x : ans) {
        cout << x << " ";
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

