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

int n;
vector<int> a;
vector<vector<int> > memo;

int f(int g, int l, int r) {
    // debug(g, l, r);
    if(l > r) {
        // cout << "Free 0\n";
        return 0;
    }
    if(a[l] == g) {
        if(memo[l][r] != -1) {
            // cout << "already calculated\n";
            return memo[l][r];
        }
        // cout << "forwarded\n";
        return memo[l][r] = f(g, l + 1, r);
    }
    
    // memo[l][r] = 1e9;
    int res = INF;
    for(int i = l; i <= r; i++) {
        int left = f(a[l], l, i);
        int right = f(g, i + 1, r);
        // debug(left, right);
        res = min(res, left + right + 1);
    }
    // debug(g, l, r, res);
    return res;
}

int main() {
    cin >> n;
    a.resize(n + 1);
    memo.resize(n + 1, vector<int> (n + 1, -1));
    a[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << f(0, 0, n) << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

