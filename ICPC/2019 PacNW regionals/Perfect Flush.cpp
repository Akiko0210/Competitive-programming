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
const int N = 2e5;
int n;

vector<int> st(N * 4);
vector<int> a(N + 5);

void build(int i, int L, int R) {
    if(L == R) {
        st[i] = L;
        return;
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    build(x, L, M);
    build(y, M + 1, R);

    if(a[st[x]] <= a[st[y]]) {
        st[i] = st[x];
    } else {
        st[i] = st[y];
    }
}

int query(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return st[i];
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    int lind = n, rind = n;
    if(l <= M) {
        lind = query(x, L, M, l, r);
    }

    if(r > M) {
        rind = query(y, M + 1, R, l, r);
    }

    if(a[lind] <= a[rind]) {
        return lind;
    }

    return rind;
}

void remove(int i, int L, int R, int ind) {
    if(L == R) {
        a[L] = 1e9;
        return;
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    if(ind <= M) {
        remove(x, L, M, ind);
    } else {
        remove(y, M + 1, R, ind);
    }

    if(a[st[x]] <= a[st[y]]) {
        st[i] = st[x];
    } else {
        st[i] = st[y];
    }
}

int main() {
    int k;
    cin >> n >> k;
    vector<vector<int> > pos(k + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    a[n] = 1e9;
    build(0, 0, n - 1);
    set<pii> last;
    for(int i = 1; i <= k; i++) {
        last.insert({pos[i].back(), i});
    }

    vector<int> ans;
    int l = 0;
    for(int i = 0; i < k; i++) {
        int r = last.begin()->first;
        int minind = query(0, 0, n - 1, l, r);
        int num = a[minind];
        l = minind + 1;
        last.erase({pos[num].back(), num});
        ans.push_back(num);
        for(int x : pos[num]) {
            remove(0, 0, n - 1, x);
        }
    }

    for(int x : ans) {
        cout << x << " ";
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

