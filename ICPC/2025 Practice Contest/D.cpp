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

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}

int lis(vector<int> a) {
    vector<int> dp;
    for(int x : a) {
        auto it = upper_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.pb(x);
        else *it = x;
    }
    return dp.size();
}

int main() {
    /*
    if q(l, r) == q(l, r + 1), a[r + 1] is greater than any other number in [l, r] segment.
    if q(l, r) + x == q(l, r + 1), a[r + 1] is less than x of numbers in [l, r] segment.

    if we know the ordering of [l, r], from query(l, r) and query(l, r + 1), we can order [l, r + 1].
    q(l, l + 1) == 1 -> a[l] > a[l + 1]
    q(l, l + 1) == 0 -> a[l] < a[l + 1]
    Easy problem?
    */

    int n;
    cin >> n;
    vector<int> pos(n + 1, -1);
    pos[1] = 0;
    int prev = 0;
    for(int i = 2; i <= n; i++) {
        int res = query(1, i);
        // a[i] is less than x of them
        int x = res - prev;
        // out of first i - 1 numbers, a[i] is greater than i - 1 - x.
        x = i - 1 - x;
        /*
        a[i] is greater than x of them. 
        if we say [0, i - 1] is from [1, i] in values, a[i] = x + 1 and values [x + 1, i] should increment by 1.
        */ 
        for(int j = i; j > x + 1; j--) {
            pos[j] = pos[j - 1];
        }
        pos[x + 1] = i - 1;
        prev = res;
    }
    vector<int> a(n);
    for(int i = 1; i <= n; i++) {
        a[pos[i]] = i;
    }
    cout << "! " << lis(a) << endl;
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

