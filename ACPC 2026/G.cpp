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
    int n;
    cin >> n;
    vector<string> mat(n);
    for(auto &s : mat) {
        cin >> s;
    }

    int c = n / 2;
    vector<pii> arr;

    auto add = [&] (int i, int j) {
        int mn = INF, mx = 0;
        for(int dx = 0; dx <= 1; dx++) {
            for(int dy = 0; dy <= 1; dy++) {
                int DX = abs(c - (i + dx)), DY = abs(c - (j + dy));
                int dis = DX * DX + DY * DY;
                mn = min(mn, dis);
                mx = max(mx, dis);
            }
        }
        arr.pb({mn, mx});
        // double ans = mn;
        // return sqrt(ans);
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == '#') {
                add(i, j);
            }
        }
    }

    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<int> > pq;
    int max_inter = 0, maxdis = 0;
    for(auto &el : arr) {
        while(!pq.empty() && pq.top() < el.ff) {
            pq.pop();
        }
        pq.push(el.ss);
        if(pq.size() > max_inter) {
            max_inter = pq.size();
            maxdis = el.ff;
        }
        // intersects with el.
    }

    cout << fixed << setprecision(10) << sqrt(double(maxdis)) << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

