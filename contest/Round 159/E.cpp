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

const ll MOD = 1e9 + 9;
const ll mod = 1e9 + 7;

int gen_base(int before, int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}


int main() {
    FAST
    ll n, sum = 0, ans = 0;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        sum += s[i].size();
    }

    ans = sum * 2 * n;

    ll base = gen_base(1000, 1000000000);
    unordered_map<ll, ll> cnt;
    for(int i = 0; i < n; i++) {
        ll hash = 0, hash1 = 0, m = s[i].size();
        for(int j = 0; j < m; j++) {
            hash = (hash * base + s[i][m - 1 - j]) % MOD;
            hash1 = (hash1 * base + s[i][m - 1 - j]) % mod;
            cnt[hash * mod + hash1]++;
        }
    }

    for(int i = 0; i < n; i++) {
        ll hash = 0, hash1 = 0, m = s[i].size(), sub = 0;
        for(int j = 0; j < m; j++) {
            hash = (hash * base + s[i][j]) % MOD;
            hash1 = (hash1 * base + s[i][j]) % mod;
            ans -= cnt[hash * mod + hash1] * 2;
        }
    }

    cout << ans << "\n";

    


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

