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
    ifstream cin("lostcow.in");
    ofstream cout("lostcow.out");

    int x, y;
    cin >> x >> y;
    bool turn = false;
    if(x > y) {
        swap(x, y);
        turn = true;
    }

    int prev = 0, cur = 1, ans = 0;
    while(x < y) {
        int move = (prev + cur) * (turn ? -1 : 1);
        x += move;
        ans += abs(move);
        prev = cur;
        cur *= 2;
        turn = !turn;
    }

    cout << ans - (x - y) << "\n";

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

