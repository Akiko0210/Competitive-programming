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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    if(n == 1) {
        cout << "0\n";
        return;
    }

    int mn = *min_element(a.begin(), a.end());

    if(mn == 1) {
        for(int i = 0; i < n; i++) {
            if(a[i] > 1) {
                cout << "-1\n";
                return;
            }
        }
        cout << "0\n";
        return;
    }

    priority_queue<pii> pq;
    for(int i = 0; i < n; i++) {
        pq.push({a[i], i});
    }

    vector<pii> ans;

    while(true) {
        pii el1 = pq.top();
        pq.pop();
        pii el2 = pq.top();
        vector<pii> temp;
        while(el2.ff == el1.ff) {
            temp.pb(el2);
            pq.pop();
            if(pq.empty()) break;
            el2 = pq.top();
        }
        if(pq.empty()) break;

        for(auto el : temp) {
            pq.push(el);
        }
        if(el1.ff == 2) break;

        ans.pb({el1.ss, el2.ss});
        pq.push({(el1.ff - 1) / el2.ff + 1, el1.ss});
    }

    cout << ans.size() << "\n";
    for(pii el : ans) {
        cout << el.ff + 1 << ' ' << el.ss + 1 << "\n";
    }

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
