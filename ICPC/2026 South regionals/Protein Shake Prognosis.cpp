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

int main() {
    ll n, bu, pu;
    cin >> n >> bu >> pu;
    vector<pair<ll, ll> > a(n), less;
    for(int i = 0; i < n; i++) {
        cin >> a[i].ff >> a[i].ss;
        if(bu > a[i].ff) {
            less.pb(a[i]);
        }
    }

    sort(less.rbegin(), less.rend());
    priority_queue<ll, vector<ll>, greater<>> pq;
    ll cursum = 0, maxpbonus = 0;
    for(auto &[b, p] : less) {
        // rem is increasing
        ll rem = bu - b;
        // pq.push();
        pq.push(p);
        cursum += p;
        while(pq.size() > rem) {
            ll least = pq.top();
            cursum -= least;
            pq.pop();
        }

        while (!pq.empty() && pq.top() < (ll)pq.size() - 1) {
            cursum -= pq.top();
            pq.pop();
        }
        
        ll m = pq.size();
        maxpbonus = max(maxpbonus, cursum - m * (m - 1) / 2);
    }

    bu += maxpbonus;
    bu += pu;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].ff + a[i].ss < bu) {
            cnt++;
        }
    }

    cout << cnt << "\n";




    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

