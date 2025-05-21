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

const ll MOD = 998244353;
int n;
int cnt[20], a[1<<19];


pair<int, ll> cal(int lvl, int l, int r) {
    if(l == r) {
        return {a[l], 1};
    }

    int m = (l + r) / 2;
    pair<int, ll> left, right;
    left = cal(lvl + 1, l, m);
    right = cal(lvl + 1, m + 1, r);
    ll ans = left.ss * right.ss % MOD;
    if(left.ff > (1 << lvl) || right.ff > (1 << lvl)) {
        return {-1, 0};
    }

    if(left.ff == -1 && right.ff == -1) {
        return {-1, ans * (cnt[lvl]--) % MOD * 2 % MOD};
    }

    if(left.ff != -1 && right.ff == -1) {
        if(left.ff > (1 << (lvl - 1))) {
            return {-1, ans};
        } 
        return {left.ff, ans * (cnt[lvl]--) % MOD};
    }

    if(right.ff != -1 && left.ff == -1) {
        if(right.ff > (1 << (lvl - 1))) {
            return {-1, ans};
        } 
        return {right.ff, ans * (cnt[lvl]--) % MOD};
    }

    return {min(right.ff, left.ff), ans};
}

int mxbit(int x) {
    if(x == 1) return 0;
    for(int i = 1; i < 20; i++) {
        if((1 << (i - 1)) < x && x <= (1 << i)) {
            return i;
        }
    }
    return 0;
}

int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        if(i == 0) cnt[i] = 1;
        else cnt[i] = (1 << i) - (1 << (i - 1));
    }
    for(int i = 0; i < (1 << n); i++) {
        cin >> a[i];
        if(a[i] != -1) {
            cnt[mxbit(a[i])]--;
        }
    } 
    int l = 0, r = (1 << n) - 1;
    cout << cal(1, l, r).second << "\n";


    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
