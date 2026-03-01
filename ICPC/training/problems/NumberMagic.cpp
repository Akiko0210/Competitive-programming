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

ll op1(ll a) {
    ll temp = a, d = 0, add = 0, cur = 1;
    while(temp > 0) {
        temp /= 10;
        add += cur;
        cur *= 10;
    }

    return a + add;
}

ll op2(ll a) {
    return a / 2;
}

int main() {
    ll n, q;
    cin >> n >> q;
    /*
    n <= 1e16
    q <= 1e3

    7 -> 43
    7 8 9 10 21 32 43
    
    - In some cases, applying op2 doens't make sense. 
    For example, if N_i < 10 and M >= 10.
    
    */

    while(q--) {
        ll m;
        cin >> m;
        unordered_map<ll, ll> prev;
        queue<ll> list;
        list.push(n);
        while(true) {
            ll cur = list.front();
            list.pop();
            if(cur == m) break;
            ll a = op1(cur), b = op2(cur);
            if(prev.find(a) == prev.end()) {
                prev[a] = cur;
                list.push(a);
            }

            if(prev.find(b) == prev.end()) {
                prev[b] = cur;
                list.push(b);
            }
        }

        while(m != n) {
            cout << m << " ";
            m = prev[m];
        }
        cout << "\n";
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

