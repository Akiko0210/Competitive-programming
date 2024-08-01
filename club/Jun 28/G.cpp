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
    /*
        can't have more than 1 decreasing subsegment.
    
    */
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    bool started = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            if(a[i] < a[i - 1]) {
                cnt += !started;
                started = true;
            } else {
                started = false;
            }
        }
    }
    if(cnt > 1) {
        cout << "no\n";
        return 0;
    }
    if(cnt == 0) {
        cout << "yes\n1 1\n";
        return 0;
    }
    int l = -1, r = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i - 1]) {
            r = i;
            if(l == -1) {
                l = i - 1;
            }
        }
    }
    if((l > 0 && a[r] < a[l - 1]) || (r < n - 1 && a[l] > a[r + 1])) {
        cout << "no\n";
    } else {
        cout << "yes\n" << l + 1 << " " << r + 1 << "\n";
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

