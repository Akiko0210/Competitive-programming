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
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    vector<int> prev(n, -1), nxt(n, n);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && s[st.top()] <= s[i]) {
            st.pop();
        }
        prev[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }
    st = stack<int>();
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && s[st.top()] < s[i]) {
            st.pop();
        }
        nxt[i] = (st.empty() ? n : st.top());
        st.push(i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        // debug(i, prev[i], nxt[i]);
        ans += (ll)(s[i] - '0') * ((ll)(nxt[i] - i) * (ll)(i - prev[i]));
    }
    ll bot = (ll)n * (n + 1) / 2;
    ll w = ans / bot;
    ans %= bot;
    if(ans == 0) {
        cout << w << "\n";
    } else {
        ll g = gcd(ans, bot);
        ans /= g;
        bot /= g;
        if(w)
            cout << w << " ";
        cout << ans << "/" << bot << "\n";
    }

    /*
    1010
    1, 10, 101, 1010 -> 4
    0, 01, 010, -> 2
    1, 10 -> 2
    0 -> 0
    8 total
    
    */

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

