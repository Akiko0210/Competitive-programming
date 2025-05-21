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

vector<ll> cnt_sum(N * 4), sum(N * 4), a(N), mn(N * 4);

void upd(int i, int L, int R, int ind, int x) {
    if(L == R) {
        cnt_sum[i] = 1;
        sum[i] = x;
        mn[i] = x;
        return;
    }
    int M = (L + R) / 2;

    if(M >= ind) {
        upd(i * 2 + 1, L, M, ind, x);
    } else {
        upd(i * 2 + 2, M + 1, R, ind, x);
    }

    mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
    sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
    cnt_sum[i] = cnt_sum[i * 2 + 1] + cnt_sum[i * 2 + 2];
}

pair<pair<ll, ll>, ll> find_sum(int i, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        return {{cnt_sum[i], sum[i]}, mn[i]};
    }

    int M = (L + R) / 2;
    pair<pair<ll, ll>, ll> res = {{0, 0}, 1000000};
    if(M < r) {
        auto el = find_sum(i * 2 + 2, M + 1, R, l, r);
        res.first.first += el.first.first;
        res.first.second += el.first.second;
        res.second = min(res.second, el.second);
    } else {
        auto el = find_sum(i * 2 + 1, L, M, l, r);
        res.first.first += el.first.first;
        res.first.second += el.first.second;
        res.second = min(res.second, el.second);
    }
    return res;
}




void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n * 4; i++) {
        sum[i] = 0;
        cnt_sum[i] = 0;
        mn[i] = 1e6;
    }

    map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]] = 0;
    }
    int i = 0;
    for(auto &el : m) {
        el.second = i++;
    }
    for(int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }

    ll ans = 0, past = 0;

    for(int i = 0; i < n; i++) {
        // a[i] deer i;
        ll cnt = 1, temp = 0;
        for(int j = 0; j < i; j++) {
            if(a[j] > a[i]) {
                temp += cnt * (i - j);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if(temp > 0) {
            past = temp;
        }
        ans += past;

        // auto res = find_sum(0, 0, n - 1, a[i], n - 1);
        // if(res.second == 1000000) {
        //     res.second = 0;
        // }
        // ans += res.first.first * i - res.first.second + (res.second) * (i - res.second);
        // upd(0, 0, n - 1, a[i], i);
    }

    cout << ans << "\n";
}

int main() {
    int t;
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
