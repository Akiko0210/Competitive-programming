/*
Lagrangian Relaxation
*/ 

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> pre(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }


    auto check = [&](ll m) -> pair<ll, ll> {
        vector<ll> dp(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        auto comp = [&](int i, int j) {
            ll ival = dp[i] - pre[i], jval = dp[j] - pre[j];
            if(ival > jval) return true;
            if(ival == jval) return cnt[i] < cnt[j];
            
            return false;
        };
        
        int mx = 0;
        // mx takes max dp min cnt. 
        for(int i = 1; i <= n; i++) {
            ll dsum = dp[mx] + pre[i] - pre[mx] - m;

            if(dsum >= dp[i - 1]) {
                dp[i] = dsum;
                if(dsum == dp[i - 1]) {
                    cnt[i] = min(cnt[i - 1], cnt[mx] + 1);
                } else {
                    cnt[i] = cnt[mx] + 1;
                }
            } else {
                dp[i] = dp[i - 1];
                cnt[i] = cnt[i - 1];
            }

            if(comp(i, mx)) {
                mx = i;
            }
        }
        return {dp[n], cnt[n]};
    };

    ll l = 0, r = 1e15;
    while(l < r) {
        ll m = (l + r) / 2;
        auto [sum, cnt] = check(m);
        if(cnt <= k) {
            r = m;
        } else {
            l = m + 1;
        }
    }

    auto [sum, cnt] = check(l);
    cout << sum + l * cnt << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

