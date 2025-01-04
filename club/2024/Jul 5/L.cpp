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

const int N = 1e5;
vector<int> stree(N * 4);
vector<int> a;

void build(int i, int L, int R) {
    if(L == R) {
        stree[i] = a[i];
        return;
    }
    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    build(x, L, M);
    build(y, M + 1, R);
    stree[i] = stree[x] + stree[y];
}

int find(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return stree[i];
    }
    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2, lval = 0, rval = 0;
    if(l <= M) {
        lval = find(x, L, M, l, r);
    }
    if(r > M) {
        rval = find(y, M + 1, R, l, r);
    }

    return lval + rval;
}

void update(int i, int L, int R, int ind, int val) {
    if(L == R) {
        stree[i] = val;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(ind <= M) {
        update(x, L, M, ind ,val);
    } else {
        update(y, M + 1, R, ind, val);
    }
    stree[i] = stree[x] + stree[y];
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

