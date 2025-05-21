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

const ll MOD = 1e9 + 7;

void solve() {
    ll n, cnt = 0, piece = 0, sum = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += abs(a[i]);
        if((cnt > 0 && a[i] <= 0) || (cnt == 0 && a[i] < 0)) {
            cnt = 1;
        } else {
            if(cnt > 0) {
                piece ++;
            }
            cnt = 0;
        }
    }
    if(cnt > 0) {
        piece++;
    }
    cout << sum << " " << piece << "\n";
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



/*
6
[-1]/ 7 \[-4 -2] /5\[-8]
4 -> 5 = 3 + 2 -> -1:3, +1:2
3 -> 4 = 2 + 2
*/