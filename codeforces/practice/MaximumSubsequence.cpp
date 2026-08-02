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

vector<int> build(vector<int>& a, int l, int r, int m) {
    int len = r - l + 1;
    unordered_set<ll> s;
    for(int i = 0; i < (1 << len); i++) {
        ll sum = 0;
        for(int j = 0; j < len; j++) {
            if((1 << j) & i) {
                sum += a[j + l];
            }
        }
        s.insert(sum % m);
    }
    vector<int> ans;
    for(int x : s) {
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> first_half = build(a, 0, n / 2, m), second_half = build(a, n / 2 + 1, n - 1, m);
    int r = first_half.size() - 1, ans = (first_half.back() + second_half.back()) % m;
    for(int x : second_half) {
        while(r > 0 && x + first_half[r] >= m) {
            r--;
        }
        ans = max(ans, (x + first_half[r]) % m);
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

