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
const int N = 3e5 + 1;

vector<char> color(N * 4, 0);
vector<bool> blocked(N, false);

// void build(int i, int L, int R) {
//     if(L == R) {
//         color[i] = 'a';
//         return;
//     }

//     int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
//     build(x, L, M);
//     build(y, M + 1, R);
// }

void propagate(int i, int L, int R) {
    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(color[i] != 0) {
        if(L < M || !blocked[L]) color[x] = color[i];
        if(M + 1 < R || !blocked[R]) color[y] = color[i];

        color[i] = 0;
    }
}

void update(int i, int L, int R, int ind) {
    // debug(i, L, R, color[i]);
    if(L == R) {
        blocked[L] = !blocked[L];
        return;
    }

    propagate(i, L, R);
    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(ind <= M) update(x, L, M, ind);
    else update(y, M + 1, R, ind);
}

char find(int i, int L, int R, int ind) {
    if(L == R) {
        return color[i];
    }
    propagate(i, L, R);

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(ind <= M) return find(x, L, M, ind);

    return find(y, M + 1, R, ind);
}

int main() {
    int n, q;
    cin >> n >> q;
    color[0] = 'a';
    // build(0, 1, n);
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int pos;
            cin >> pos;
            update(0, 0, n, pos);
        } else {
            char c;
            cin >> c;
            // if(n == 1 && blocked[1]) continue;
            color[0] = c;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << find(0, 0, n, i);
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

