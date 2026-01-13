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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int mx = 0, mn = 0, mn_dis = n, mx_cnt = 0, mn_cnt = 0;
    for(int i = 0; i < k; i++) {
        vector<int> temp = {0, 1};
        int cur = 1;
        for(int j = i; j + 1 <= n - k; j += k) {
            if(s[j] != s[j + 1]) {
                cur = 1 - cur;
            }
            temp[cur]++;
        }
        /*
        5 2
        1001
        1-0-1
        -1-1-
        
        */
        // debug(i, temp[0], temp[1]);
        // assuming s[i] = 1. It can be 0 too.
        if(temp[0] > temp[1]) {
            // it was better s[i] = 0;
            mn_dis = min(mn_dis, temp[0] - temp[1]);
            mx += temp[0];
            mn += temp[1];
            mn_cnt ^= 1;
        } else {
            // it was better s[i] = 1;
            mn_dis = min(mn_dis, temp[1] - temp[0]);
            mx += temp[1];
            mn += temp[0];
            mx_cnt ^= 1;
        }
    }

    if(mx_cnt != s[0] - '0') {
        mx -= mn_dis;
    }
    if(mn_cnt != s[0] - '0') {
        mn += mn_dis;
    }

    cout << mn << " " << mx << "\n";


}

int main() {
    FAST
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

