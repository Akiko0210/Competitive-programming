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
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    vector<int> inds(1e5 + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        inds[d[i]] = i;
    }

    vector<bool> curcoins(n, true);
    vector<pair<char, int> > q(m);
    int mx = 0;
    for(int i = 0; i < m; i++) {
        cin >> q[i].first >> q[i].second;
        mx = max(mx, q[i].second);
        if(q[i].first == 'X') 
            curcoins[inds[q[i].second]] = false;
    }

    vector<int> dp(mx + 1, 1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        if(!curcoins[i]) continue;

        // debug(i);

        for(int j = d[i]; j <= mx; j++) {
            dp[j] = min(dp[j], dp[j - d[i]] + 1);
        }
    }


    reverse(q.begin(), q.end());


    vector<int> ans;
    for(auto el : q) {
        if(el.first == 'Q') {
            ans.push_back(dp[el.second]);
        } else {
            int ind = inds[el.second];
            for(int j = d[ind]; j <= mx; j++) {
                dp[j] = min(dp[j], dp[j - d[ind]] + 1);
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for(int x : ans) {
        cout << (x == 1e9 ? -1 : x) << "\n";
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

