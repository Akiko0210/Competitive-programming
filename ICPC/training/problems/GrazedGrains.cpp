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

struct Ufo {
    int x, y, r;
    Ufo(){}
    Ufo(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
};

int main() {
    int n, zoom = 10;
    cin >> n;
    vector<Ufo> ufos(n);
    for(int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        ufos[i] = Ufo(x * zoom, y * zoom, r * zoom);
    }

    int cnt = 0;
    for(int x = -zoom*zoom; x <= 2 * zoom * zoom; x++) {
        for(int y = -zoom*zoom; y <= 2 * zoom * zoom; y++) {
            for(int i = 0; i < n; i++) {
                int dx = abs(ufos[i].x - x);
                int dy = abs(ufos[i].y - y);
                if(dx * dx + dy * dy <= ufos[i].r * ufos[i].r) {
                    cnt++;
                    break;
                }
            }
        }
    }

    double ans = double(cnt) / zoom / zoom;
    cout << ans << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

