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
    int n;
    cin >> n;
    vector<int> a(n);
    array<vector<int>, 2> nums;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        nums[i % 2].pb(a[i]);
    }

    sort(nums[0].rbegin(), nums[0].rend());
    sort(nums[1].rbegin(), nums[1].rend());
    for(int i = 0; i < n; i++) {
        int mn_container = 0;
        if(nums[0].empty()) mn_container = 1;
        else if(nums[1].empty()) mn_container = 0;
        else mn_container = nums[0].back() < nums[1].back() ? 0 : 1;


        if(nums[mn_container].size() < nums[1 - mn_container].size()) {
            cout << "NO\n";
            return;
        }
        nums[mn_container].pop_back();
    }

    cout << "YES\n";
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

