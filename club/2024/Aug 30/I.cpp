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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pii> intervals;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            intervals.pb({min(a[i], a[i - 1]), max(a[i], a[i - 1])});
        }
    }

    sort(intervals.begin(), intervals.end());
    int prev = -1e7;
    set<int> allends;

    for(int i = 0; i < n - 1; i++) {
        while(!allends.empty() && *allends.begin() < intervals[i].ff) {
            allends.erase(allends.begin());
        }

        if(intervals[i].ff != prev) {
            auto it = allends.begin();
            // if(it != allends.end() && *it <) {
            //     cout << "yes\n";
            //     return 0;
            // }
        }
        prev = intervals[i].ff;
        // curends.insert(intervals[i].ss);
    }

    cout << "no\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

