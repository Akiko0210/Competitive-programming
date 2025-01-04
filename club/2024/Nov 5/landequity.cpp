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
    int r, c;
    cin >> r >> c;
    vector<ll> cnt(3);
    vector<vector<int> > a(r, vector<int> (c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }

    if(r == 1 || c == 1) {
        if(r == 1) {
            long long p1 = 1, p2 = 1, ans = INT64_MAX;
            for(int i = 0; i < c - 1; i++) {
                p1 *= a[0][i];
                p2 = 1;
                for(int j = i + 1; j < c; j++) {
                    p2 *= a[0][j];
                }
                ans = min(ans, abs(p1 - p2));
            }
            cout << ans << "\n";
            return 0;
        }   
        if(c == 1) {
            long long p1 = 1, p2 = 1, ans = INT64_MAX;
            for(int i = 0; i < r - 1; i++) {
                p1 *= a[i][0];
                p2 = 1;
                for(int j = i + 1; j < r; j++) {
                    p2 *= a[j][0];
                }
                ans = min(ans, abs(p1 - p2));
            }
            cout << ans << "\n";
            return 0;
        }
    }


    if(cnt[0] > 0) {
        cnt[0]--;
        for(int i = 0; i < 3; i++) {
            if(cnt[i] > 0) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    /*
        land score will be power of 2. 

    
    */ 
    ll half = cnt[2] / 2;
    if(cnt[2] & 1) {
        cout << (1LL << half) << "\n";
        return 0;
    }
    cout << "0\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

