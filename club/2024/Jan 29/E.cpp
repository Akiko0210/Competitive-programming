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
    int t = 1;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        /*
        line = max(x, y)
        if line is odd :
        ->  ^
            |

        if even : 
        |  <-
        v
        */

        ll line = max(x, y);
        ll base = (line - 1) * (line - 1);
        if(line & 1) {
            if(y < line) {
                cout << base + y << "\n";
                continue;
            }
            cout << base + line + (line - x) << "\n";
        } else {
            if (x < line) {
                cout << base + x << "\n";
                continue;
            }
            cout << base + line + (line - y) << "\n";
        }
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

