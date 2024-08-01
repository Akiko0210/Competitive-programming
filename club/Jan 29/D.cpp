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

int main() {
    /*
    n = 2
    NO
    n = 3
    NO
    n = 4
    3 1 4 2
    n = 5
    3 1 4 2 5
    */

    int n;
    cin >> n;
    if(n == 1) {
        cout << "1\n";
        return 0;
    }

    if(n <= 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        if(i & 1) {
            cout << i / 2 + 1 << " ";
        } else {
            cout << n / 2 + i / 2 + 1 << " ";
        }
    }
    cout << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

