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
const int N = 3e5;
ll sum[N * 4];
bool canmerge[N * 4];
vector<ll> a(N);

void build(int i, int L, int R) {
    if(L == R) {
        sum[i] = a[L];
        canmerge[i] = false;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    build(x, L, M);
    build(y, M + 1, R);

    sum[i] = sum[x] + sum[y];
    ll lefteach = sum[x] / (M - L + 1), righteach = sum[y] / (R - M);
    canmerge[i] = !(lefteach == righteach && !canmerge[x] && !canmerge[y]);
}

pair<pair<ll, int>, bool> query(int i, int L, int R, int l, int r) {
    // if(i != -1)
    //     debug(i, L, R, l, r);
    if(l <= L && r >= R) {
        return {{sum[i], R - L + 1}, canmerge[i]};
    }
   
    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(l <= M && r <= M) {
        return query(x, L, M, l, r);
    }
    if(l > M && r > M) {
        return query(y, M + 1, R, l, r);
    }

    pair<pair<ll, int>, bool> left, right;
    left = query(x, L, M, l, r);
    right = query(y, M + 1, R, l, r);
    ll lefteach = left.ff.ff / left.ff.ss, righteach = right.ff.ff / right.ff.ss;
    bool mymerge = lefteach != righteach || left.second || right.second;
    ll sum = left.ff.ff + right.ff.ff, cnt = left.ff.ss + right.ff.ss;

    return {{sum, cnt}, mymerge};
}

vector<int> ans(N, INF);
int n;

void leftcheck(int i) {
    if(i == 0) return;
    

    if(a[i - 1] > a[i]) {
        ans[i] = 1;
        return;
    }

    int l = 0, r = i - 1;
    while(l < r) {
        // debug(l, r);
        int m = (l + r + 1) / 2;
        pair<pair<ll, int>, bool> val = query(0, 0, n - 1, m, i - 1);
        // debug(m, i - 1, val.second, val.ff.ff);
        if(!val.second || val.ff.ff <= a[i]) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    pair<pair<ll, int>, bool> temp = query(0, 0, n - 1, l, i - 1);
    // debug(l, i - 1, a[i], temp.ff.ff, temp.ff.ss, temp.ss);
    if(temp.ss && temp.ff.ff > a[i]) {
        ans[i] = min(ans[i], temp.ff.ss);
    }
}

void rightcheck(int i) {
    if(i == n - 1) return;

    if(a[i] < a[i + 1]) {
        ans[i] = 1;
        return;
    }

    int l = i + 1, r = n - 1;
    while(l < r) {
        // debug(l, r);
        int m = (l + r) / 2;
        pair<pair<ll, int>, bool> val = query(0, 0, n - 1, i + 1, m);
        // debug(i + 1, m, val.second, val.ff.ff);
        if(!val.second || val.ff.ff <= a[i]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    // debug(i + 1, r);
    pair<pair<ll, int>, bool> temp = query(0, 0, n - 1, i + 1, r);
    // debug(i + 1, r, a[i], temp.ff.ff, temp.ff.ss, temp.ss);
    if(temp.ss && temp.ff.ff > a[i]) {
        ans[i] = min(ans[i], temp.ff.ss);
    }
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    // cout << "build done!\n"
    for(int i = 0; i < n; i++) {
        // eaten left:
        // debug(i);
        leftcheck(i);
        rightcheck(i);
        // debug(ans[i]);
    }
    for(int i = 0; i < n; i++) {
        cout << (ans[i] == INF ? -1 : ans[i]) << " ";
        ans[i] = INF;
    }
    cout << "\n";

 
    /*
        for each slime min time to be eaten
        1) slime can be eaten from left or right.
        we can canmerge and sparse table.
    */



}

int main() {
    FAST
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
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

