#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
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

pair<int, pii> calc(int x, int y) {
    // ehnii index
    int cnt = x > y;

    if(x > y) {
        swap(x, y);
    }

    ll cycle = y / x - cnt;
    ll t_cycle = cycle / 2 * 3 + cycle % 2;
    // debug(t_cycle, x, y, cnt);
    return {t_cycle + cnt + 1 - !(cycle & 1), (cycle & 1 ? mp(y % x, x) : mp(x, y % x))}; // {*, 1} -> lower urdaa 
}

void solve() {
    // 2 5 3 2 1 1 0
    
    // 1 2 1 1 0 1
    // 2 1 1 0 1 0

    // 19 2 17 15 2 13 11 2 9 7 2 5 3 2 1 1 0
    // 2 19 17 2 

    // 19 7 12 5 7 2 5 3 2 1 1 0
    // 7 19 12 7 5

    // 1 7 6 1 5 4 1 3 2 1 1 0 1 1 0
    // 2 6 4 2 2 0 2 2 0 2 2 0
    // 3 5 2 3 1 2 1 1 0 1 1 0 
    // 4 4 0 4 4 0 4 4 0 4 4 0
    // 6 2 4 2 2 0
    // 7 1 6 5 1 4 3 1 2 1 1 0
    // 6 3 3 0
    // 3 6 3 3 0
    // 12 9 3 6 3 3 0
    // x > y
    // x (y * *) * (x / y / 2) 


    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == b[i] && a[i] == 0) {
            continue;
        }
        int pos = 0;
        while(a[i] > 0 && b[i] > 0) {
            auto temp = calc(a[i], b[i]);
            pos += temp.ff % 3;
            a[i] = temp.ss.ff;
            b[i] = temp.ss.ss;
            // debug(pos, a[i], b[i]);

        }
        pos += a[i] > b[i];
        if(i == 0) {
            ans = pos % 3;
        } else {
            if(ans != (pos % 3)) {
                cout << "NO\n";
                return;
            }
        }
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
