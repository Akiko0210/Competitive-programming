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

struct nile {
    ll W, A, B, D;
    nile(int w, int a, int b) {
        W = w;
        A = a;
        B = b;
        D = A - B;
    }
};

std::vector<long long> calculate_costs(
std::vector<int> W, std::vector<int> A,
std::vector<int> B, std::vector<int> E) {
    int n = W.size(), q = E.size();
    vector<nile> niles(n);
    for(int i = 0; i < n; i++) {
        niles[i] = nile(W[i], A[i], B[i]);
    }
    sort(niles.begin(), niles.end(), [](nile a, nile b) {
        return a.W < b.W;
    });

    vector<ll> ans(q, B[0]);
    for(int i = 0; i < q; i++) {
        ll D = E[i], s = 0, mneven = A[0] - B[0], mnodd = INF;

        for(int j = 1; j < n; j++) {
            ans[i] += B[j];
            if(W[j])
            if((j - s) % 2 == 0) {
                mneven = min(mneven, (ll)A[j] - B[j]);
            }
            // if((j - s) % 2 == 1 && )
        }


        
    }

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

