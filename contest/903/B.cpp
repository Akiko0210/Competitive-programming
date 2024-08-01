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

void solve() {
    ll sum = 0;
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sum = a[0] + a[1] + a[2];
    // debug(sum);
    if(sum % 3 && sum % 4 && sum % 5 && sum % 6) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < 4; i++) {
        if(sum % (i + 3)) continue;

        priority_queue<ll> pq;
        for(int i = 0; i < 3; i++) {
            pq.push(a[i]);
        }

        ll goal = sum / (i + 3);
        // debug(goal);
        for(int j = 0; j < i; j++) {
            ll cur = pq.top();
            if(cur > goal) {
                pq.pop();
                pq.push(goal);
                pq.push(cur - goal);
            }
        }
        bool ans = true;
        while(!pq.empty()) {
            if(pq.top() != goal) {
                ans = false;
                break;
            }
            pq.pop();
        }
        if(ans) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
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
