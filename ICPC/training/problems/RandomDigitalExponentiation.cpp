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

vector<int> ans;
vector<vector<int> > cycle(10);
vector<vector<ll> >  p(10);


bool solve(vector<int>& d, ll b) {
    if(d.empty()) {
        return b == 0;
    }
    if(b % 10 == 0) 
        return false;
    
    int lastDigit = b % 10, last = d.back();
    if(lastDigit == 1) {
        // try 0.
        d.pop_back();
        bool can = solve(d, b / 10);
        if(can) {
            ans.pb(0);
            return true;
        }
        d.push_back(last);
    }

    auto it = find(cycle[last].begin(), cycle[last].end(), lastDigit);
    if(it == cycle[last].end()) {
        // try plugging 0.
        return false;
    }

    int ind = it - cycle[last].begin(), s = cycle[last].size();
    for(int i = ind; i < p[last].size() && b >= p[last][i]; i += s) {
        d.pop_back();
        bool can = solve(d, (b - p[last][i]) / 10);
        if(can) {
            ans.pb(i + 1);
            return true;
        }
        d.pb(last);
    }
    return false;
}

int main() {
    ll a, b;
    cin >> a >> b;
    vector<int> d;
    while(a) {
        d.pb(a % 10);
        a /= 10;
    }
    reverse(d.begin(), d.end());

    for(int i = 2; i < 10; i++) {
        ll j = i;
        cycle[i].pb(i);
        while((j * i) % 10 != i) {
            (j *= i) %= 10;
            cycle[i].pb(j);
        }

        j = i;
        p[i].pb(j);
        while(j * i <= 1e10) {
            j *= i;
            p[i].pb(j);
        }
    }

    solve(d, b);
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

