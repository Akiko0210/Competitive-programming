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

vector<int> stree, arr;

void build(int i, int L, int R) {
    if(L == R) {
        stree[i] = arr[L];
        return;
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2;
    build(x, L, M);
    build(y, M + 1, R);
    stree[i] = min(stree[x], stree[y]);
}

void buildstree(int n, int k) {
    stree.resize(n * 4, 2 * n);
    arr.resize(n, 2 * n);
    int cur = 0, i = 0;
    while(arr[cur] == 2 * n) {
        arr[cur] = i;
        i++;
        cur = (cur + k) % n;
    }
    build(0, 0, n - 1);
}

int query(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return stree[i];
    }

    int x = i * 2 + 1, y = i * 2 + 2, M = (L + R) / 2, lval = 1e9, rval = 1e9;
    if(l <= M) {
        lval = query(x, L, M, l, r);
    }
    if(r > M) {
        rval = query(y, M + 1, R, l, r);
    }
    return min(lval, rval);
}


int main() {
    FAST
    int n, k, d, s;
    cin >> n >> k >> d >> s;
    k %= n;
    buildstree(n, k);
    

    vector<int> a(n);
    for(int &x : a) {
        cin >> x;
    }
    vector<bool> inloop(n, false);
    vector<vector<int> > loops;
    for(int i = 0; i < n; i++) {
        if(!inloop[i]) {
            vector<int> loop;
            int cur = (i + k) % n;
            while(cur != i) {
                loop.push_back(cur);
                inloop[cur] = 1;
                cur = (cur + k) % n;
            }
            loop.push_back(cur);
            loops.pb(loop);
        }
    }

    // for each loop, calculate d day sum.
    vector<ll> dsum(n, 0);
    for(auto loop : loops) {
        ll m = loop.size(), sum = 0, loopsum = 0;
        for(int i : loop) {
            loopsum += a[i];
        }
        sum += loopsum * (d / m);
        for(int i = 0; i < d % m; i++) {
            sum += a[loop[i % m]];
        }
        for(int i = 0; i < m; i++) {
            dsum[loop[i]] = sum;
            sum -= a[loop[i]] - a[loop[(i + d) % m]];
        }
    }

    ll ans = 0, cur = 0;
    for(int i = 0; i < s; i++) {
        cur += dsum[i];
    }
    ans = cur;

    /*
    i -> j <= n - s < i
    i - a * k (mod n) <= n - s AND
    a <= n - d
    
    */
    for(int i = 1; i < n; i++) {
        cur += dsum[(i + s - 1) % n] - dsum[i - 1];
        if(i <= n - s) {
            ans = max(ans, cur);
        } else {
            int dif = i - (n - s);
            // how to decrease at least dif, at most i remainder with k;
            int mn_down = query(0, 0, n - 1, dif, i);
            if(mn_down <= n - d) {
                ans = max(ans, cur);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
