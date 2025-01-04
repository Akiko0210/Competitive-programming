
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
    ifstream in ("lostcow.in");
    ofstream out("lostcow.out");
    int n, m;
    in >> n >> m;
    int ans = 0, step = 0, prev = 0, turn = 0;
    if(n > m) {
        swap(n, m);
        turn++;
    }
    while(n < m) {
        int cur = (prev + (1 << step)) * (turn & 1 ? -1 : 1);
        n += cur;
        ans += abs(cur);
        turn = 1 - turn;
        prev = (1 << step);
        step++;
    }
    out << ans - (n - m);



    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

