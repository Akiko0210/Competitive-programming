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


/*
    Ohh I got it. I was almost solved it. But I looked into the tourist solution. 
    My observation:
        If there is only 1 number that does not divide the max number, answer is N.
        If all number divides max number, I didn't know what to do. 
    Tourist solution:
        If all number divides max number, last LCM must be among the divisors of max number.
        Then run dp on the divisors of the max number. 

    Analysis:
    Even if I knew the solution, I messed a lot in the implementation. 
    1. I didn't deeply thought of running dp from back. 

*/
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> divs;
    for(int i = 1; i * i <= a.back(); i++) {
        if(a.back() % i == 0) {
            divs.pb(i);
            if(a.back() / i != i) {
                divs.pb(a.back() / i);
            }
        }
    }

    sort(divs.begin(), divs.end());
    for(int x : a) {
        auto it = lower_bound(divs.begin(), divs.end(), x);
        if(it == divs.end() || *it != x) {
            cout << n << "\n";
            return;
        }
    }
    int sz = (int)divs.size();
    vector<int> dp(sz, -1), dp1;
    dp[0] = 0;
    dp1 = dp;
    for(int i = 0; i < n; i++) {
        for(int j = sz - 1; j >= 0; j--) {
            if(dp[j] == -1) continue;
            int lcm = divs[j] / gcd(divs[j], a[i]) * a[i];
            int ind = lower_bound(divs.begin(), divs.end(), lcm) - divs.begin();
            dp[ind] = max(dp[ind], dp[j] + 1);
        }
        dp1 = dp;
    }

    // for(int i = 0; i < divs.size(); i++) {
    //     debug(divs[i], dp[i]);
    // }

    int ans = 0;

    for(int i = 0; i < (int)divs.size(); i++) {
        auto it = lower_bound(a.begin(), a.end(), divs[i]);
        if(it == a.end() || *it != divs[i]) {
            ans = max(ans, dp[i]);
        }
    }

    cout << (ans == 1 ? 0 : ans) << "\n";


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

