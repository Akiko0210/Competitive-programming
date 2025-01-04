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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> t = a;
    while(q--) {
        ll k;
        cin >> k;
        ll ans = 0;
        for(int i = 60; i >= 0; i--) {
            ll cur = 0, num = (1LL << i);
            for(int &x : t) {
                if(num & x) {
                    continue;
                }
                cur += num - x % num;
                if(cur > k) {
                    break;
                }
            }
            if(cur <= k) {
                k -= cur;
                ans += num;
                for(int &x : t) {
                    if(num & x) continue;

                    x = x / num * num;
                }
            }
        }
        t = a;
        cout << ans << "\n";
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

