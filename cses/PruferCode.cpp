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
    int n;
    cin >> n;
    vector<int> cnt(n + 1), codes(n - 2);
    for(int i = 0; i < n - 2; i++) {
        cin >> codes[i];
        cnt[codes[i]]++;
    }

    // i just think we need to sort every leaf nodes. 
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) pq.push(i);
    }

    vector<pii> ans;
    for(int x : codes) {
        int minleaf = pq.top();
        pq.pop();
        ans.push_back({x, minleaf});
        cnt[x]--;
        if(cnt[x] == 0) pq.push(x);
    }

    int x = pq.top();
    pq.pop();
    int y = pq.top();
    ans.pb({x, y});

    for(auto &[a, b] : ans) {
        cout << a << " " << b << "\n";
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

