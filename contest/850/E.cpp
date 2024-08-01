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
int LSOne(int k) {
    return k & (-k);
}
void solve() {
    int n;
    cin >> n;
    vector<int> ft(n + 1, 0);
    auto rsq = [&] (int b) {
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum; 
    };
    auto adjust = [&] (int k, int v) {
        for (; k < ft.size(); k += LSOne(k)) ft[k] += v; 
    };

    vector<int> a(n + 1, 0);
    ll sum = 0, head = 0, sum1 = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int temp = rsq(x);
        if(temp >= x) {
            cout << sum - sum1 << " ";
            continue;
        }
        a[x]++;
        adjust(x, a[x]);
        sum += x;
        sum1 += ++head;
        cout << sum - sum1 << " ";
    }
    cout << "\n";
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
