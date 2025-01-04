#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<int, int>
#define INF 1000000000000000LL
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

struct nile {
    ll W, d;
    nile(int w, int a, int b) {
        W = w;
        d = a - b;
    }
};

std::vector<long long> calculate_costs(
std::vector<int> W, std::vector<int> A,
std::vector<int> B, std::vector<int> E) {
    int n = W.size(), q = E.size();
    vector<nile> niles;
    ll curans = 0;
    for(int i = 0; i < n; i++) {
        curans += B[i];
        niles.pb(nile(W[i], A[i], B[i]));
    }

    vector eind(q, 0);
    iota(eind.begin(), eind.end(), 0);
    sort(eind.begin(), eind.end(), [&](int i, int j) {
        return E[i] < E[j];
    });
    sort(niles.begin(), niles.end(), [] (nile a, nile b) {
        return a.W < b.W;
    });

    vector dirmx (n, vector(2, INF)), conmx(n, vector(2, INF));
    
    set<int> starts;
    vector<pii> intervals, conditionals;

    for(int i = 0; i < n; i++) {
        dirmx[i][0] = niles[i].d;
        curans += dirmx[i][0];

        starts.insert(i);
        if(i > 0) {
            intervals.pb({niles[i].W - niles[i - 1].W, i});
            if(i < n - 1) 
                conditionals.pb({niles[i + 1].W - niles[i - 1].W, i});
        }
    }
    sort(intervals.begin(), intervals.end());
    sort(conditionals.begin(), conditionals.end());
    int iind = 0, cind = 0; 

    vector<ll> ans(q);
    for(int i = 0; i < q; i++) {
        int D = E[eind[i]];
        debug(i, D, eind[i]);
        // merge intervals
        while(cind < (int)conditionals.size() && D >= conditionals[cind].ff) {
            int curind = conditionals[cind].ss;
            // guaranteed mid segment. next - prev <= D -> next and prev is in same segment. 
            auto it = starts.upper_bound(curind);
            --it;
            int prev = *it, par = (curind - prev) & 1;
            // cout << curind << " is in segment " << prev << "\n";
            conmx[prev][par] = min(conmx[prev][par], niles[curind].d);
            cind++;
        }

        while(iind < (int)intervals.size() && D >= intervals[iind].ff) {
            // find previous interval. 
            int curind = intervals[iind].ss;
            auto it = starts.find(curind);
            auto nxtit = it;
            --it;
            nxtit++;
            int prev = *it, nxt = (nxtit == starts.end() ? n : *nxtit), par = (curind - prev) & 1;
            // cout << curind << " is merging to " << prev << "\n";

            starts.erase(curind);
            // when erasing, we need to update curans.
            if((nxt - curind) & 1) {
                // we added dirmax[curind][0]
                curans -= min(dirmx[curind][0], conmx[curind][1]);
            }

            if(par) {
                // we added dirmx[prev][0]
                curans -= min(dirmx[prev][0], conmx[prev][1]);
            }

            // update at prev
            for(int j = 0; j < 2; j++) {
                dirmx[prev][j] = min(dirmx[prev][j], dirmx[curind][par ^ j]);
                conmx[prev][j] = min(conmx[prev][j], conmx[curind][par ^ j]);
            }
            debug(curans, "before");
            if((nxt - prev) & 1)
                curans += min(dirmx[prev][0], conmx[prev][1]);
            debug(curans, "after");
            iind++;
        }
        ans[eind[i]] = curans;
    }
    return ans;
}



int main() {
    int n, q;
    cin >> n;
    vector<int> W(n), A(n), B(n);
    for(int i = 0; i < n; i++) {
        cin >> W[i] >> A[i] >> B[i];
    }

    cin >> q;
    vector<int> E(q);
    for(int i = 0; i < q; i++) {
        cin >> E[i];
    }

    vector<ll> ans = calculate_costs(W, A, B, E);
    
    for(ll x : ans) {
        cout << x << "\n";
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

