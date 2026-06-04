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
    ifstream cin("mowing.in");
    ofstream cout("mowing.out");
    int n;
    cin >> n;
    map<pair<int, int>, int> time;
    int curx = 0, cury = 0, t = 0, ans = INT_MAX;

    for(int i = 0; i < n; i++) {
        char c;
        int num, dx, dy;
        cin >> c >> num;
        if(c == 'W') {
            dx = 0;
            dy = 1;
        }
        if(c == 'E') {
            dx = 0;
            dy = -1;
        }

        if(c == 'N') {
            dx = 1;
            dy = 0;
        }

        if(c == 'S') {
            dx = -1;
            dy = 0;
        }

        for(int j = 0; j < num; j++) {
            t++;
            if(time.find({curx, cury}) != time.end()) {
                // debug(curx, cury, t, time[{curx, cury}]);
                ans = min(ans, t - time[{curx, cury}]);    
            }
            // debug(curx, cury);
            time[{curx, cury}] = t;
            curx += dx;
            cury += dy;
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

