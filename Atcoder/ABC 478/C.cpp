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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
        exactly k len
    */ 

    vector<bool> pre(n, true), suf(n, true);

    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1];
        if(a[i] < a[i - 1]) {
            pre[i] = false;
        }

        suf[n - 1 - i] = suf[n - i];
        if(a[n - 1 - i] > a[n - i]) {
            suf[n - 1 - i] = false;
        }
    }

    multiset<int> s;
    for(int i = 0, l = 0; i < n; i++) {
        s.insert(a[i]);
        if(i < k - 1) {
            continue;
        }

        bool goodpre = (l == 0 || pre[l - 1]);
        bool goodsuf = (i == n - 1 || suf[i + 1]);
        int mn = *s.begin(), mx = *s.rbegin();
        // debug(i, goodpre, goodsuf, mn, mx);
        if(goodpre && goodsuf && mn >= (l > 0 ? a[l - 1] : 0) && mx <= (i + 1 < n ? a[i + 1] : INF)) {
            cout << "Yes\n";
            return 0;
        }

        s.erase(s.find(a[l++]));
    }

    cout << "No\n";




    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

