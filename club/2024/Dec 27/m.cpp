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
    vector<int> r(n);
    priority_queue<pii> pq;
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> r[i];
        cnt[r[i]]++;
        
    }

    for(auto &[k, v] : cnt) {
        pq.push({v, k});
    }

    vector<vector<int> > ans;
    while(pq.size() > 2) {
        pii p1 = pq.top();
        pq.pop();
        pii p2 = pq.top();
        pq.pop();
        pii p3 = pq.top();
        pq.pop();

        ans.pb({p1.ss, p2.ss, p3.ss});
        p1.ff--;
        if(p1.ff > 0) {
            pq.push(p1);
        }
        p2.ff--;
        if(p2.ff > 0) {
            pq.push(p2);
        }
        p3.ff--;
        if(p3.ff > 0) {
            pq.push(p3);
        }
    }

    cout << ans.size() << "\n";
    for(auto el : ans) {
        sort(el.rbegin(), el.rend());
        cout << el[0] << " " << el[1] << " " << el[2] << '\n';
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

