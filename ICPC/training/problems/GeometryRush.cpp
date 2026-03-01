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
    int n, m, w, h;
    cin >> n >> m >> w >> h;
    vector<pii> toppts(n), botpts(m);
    vector<int> top(w + 1, h), bot(w + 1, -h);
    for(int i = 0; i < n; i++) {
        cin >> toppts[i].ff >> toppts[i].ss;
    }
    for(int i = 0; i < m; i++) {
        cin >> botpts[i].ff >> botpts[i].ss;
    }

    for(int i = 1; i < n; i++) {
        int startx = toppts[i - 1].ff, endx = toppts[i].ff,
        starty = toppts[i - 1].ss, endy = toppts[i].ss;
        ll dy = endy - starty, dx = endx - startx, g = gcd(dy, dx);
        if(dx == 0) {
            top[startx] = min(top[startx], endy - 1);
            continue;
        }
        dy /= g;
        dx /= g;
        for(int j = 0; j <= endx - startx; j++) {
            top[startx + j] = min((ll)top[startx + j], starty + (dy * j) / dx - 1);
        }
    }
    for(int i = 1; i < m; i++) {
        int startx = botpts[i - 1].ff, endx = botpts[i].ff,
        starty = botpts[i - 1].ss, endy = botpts[i].ss;
        ll dy = endy - starty, dx = endx - startx, g = gcd(dy, dx);
        if(dx == 0) {
            // debug(i, endy + 1, bot[startx]);
            bot[startx] = max(bot[startx], endy + 1);
            continue;
        }
        dy /= g;
        dx /= g;
        for(int j = 0; j <= endx - startx; j++) {
            bot[startx + j] = max((ll)bot[startx + j], starty + (dy * j) / dx + 1);
        }
    }

    if(top[0] < 0 || bot[0] > 0) {
        cout << "impossible\n";
        return 0;
    }

    int mx = 0, mn = 0;
    for(int x = 1; x <= w; x++) {
        // debug(top[x], bot[x]);
        if(mx + 1 <= top[x]) {
            mx++;
        } else if(mx - 1 <= top[x]) {
            mx--;
        } else {
            mx = top[x];
        }

        if(mn - 1 >= bot[x]) {
            mn--;
        } else if(mn + 1 >= bot[x]) {
            mn++;
        } else {
            mn = bot[x];
        }

        if((x & 1) != (mx & 1)) {
            mx--;
        }
        if((x & 1) != (mn & 1)) {
            mn++;
        }

        if(mx < mn) {
            cout << "impossible\n";
            return 0;
        }
    }

    cout << mn << " " << mx << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

