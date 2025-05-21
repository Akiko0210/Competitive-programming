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
const int N = 2e5 + 5;
int n, q;
vector<int> p(N), sp(N * 4), ss(N * 4);

void build(int i, int L, int R) {
    if(L == R) {
        sp[i] = p[L] + L;
        ss[i] = p[L] + n - L;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    build(x, L, M);
    build(y, M + 1, R);
    sp[i] = min(sp[x], sp[y]);
    ss[i] = min(ss[x], ss[y]);
}

void update(int i, int L, int  R, int ind, int val) {
    if(L == R) {
        p[L] = val;
        sp[i] = p[L] + L;
        ss[i] = p[L] + n - L;
        return;
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(ind <= M) {
        update(x, L, M, ind, val);
    } else {
        update(y, M + 1, R, ind, val);
    }
    sp[i] = min(sp[x], sp[y]);
    ss[i] = min(ss[x], ss[y]);
}

int query1(int i, int L, int R, int ind) {
    if(ind <= L) {
        return sp[i];
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(ind <= M) {
        return min(query1(x, L, M, ind), sp[y]);
    }

    return query1(y, M + 1, R, ind);
}

int query2(int i, int L, int R, int ind) {
    if(ind >= R) {
        return ss[i];
    }

    int M = (L + R) / 2, x = i * 2 + 1, y = i * 2 + 2;
    if(ind > M) {
        return min(query2(y, M + 1, R, ind), ss[x]);
    }

    return query2(x, L, M, ind);
}

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    build(0, 1, n);

    while(q--) {
        int op, k, x;
        cin >> op;
        if(op == 1) {
            cin >> k >> x;
            update(0, 1, n, k, x);
        } else {
            cin >> k;
            int pre = query1(0, 1, n, k) - k;
            int suf = query2(0, 1, n, k) - n + k;
            debug(pre, suf);
            cout << min(pre, suf) << "\n";
            // cout << min(query1(0, 1, n, k) - k, query2(0, 1, n, k) - n + k) << "\n";
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

