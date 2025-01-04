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
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    /*
    (a, b, c) = answer
    a + b + c = n
    a * w + b * d = p

    w > d

    drem + w * x = d * y
    */
    long long a = p / w, rem = p % w, b = rem / d, drem = rem % d;
    if(drem == 0) {
        if(a + b <= n) {
            cout << a << " " << b << " " << n - a - b << "\n";
        } else {
            cout << "-1\n";
        }
        return;
    }

    vector<int> first_ap(d, -1);
    int cur = drem, step = 0;
    while(cur > 0) {
        if(first_ap[cur] != -1) {
            break;
        }
        first_ap[cur] = step++;
        cur = (cur + w) % d;
    }
    if(cur == 0) {
        first_ap[0] = step;
    }
    if(first_ap[0] == -1) {
        cout << "-1\n";
        return;
    }

    b += (drem + w * first_ap[0]) / d;
    a -= first_ap[0];
    if(a < 0 || a + b > n) {
        cout << "-1\n";
        return;
    }
    cout << a << " " << b << " " << n - a - b << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
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

