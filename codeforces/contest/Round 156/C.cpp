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
    string s;
    ll pos;
    cin >> s >> pos;

    int n = s.size(), del = 0, cur = n;
    while(pos > cur) {
        pos -= cur--;
        del++;
    }

    vector<int> order;
    stack<int> st;
    st.push(0);
    for(int i = 1; i < n; i++) {
        while(!st.empty() && s[st.top()] > s[i]) {
            order.pb(st.top());
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        order.pb(st.top());
        st.pop();
    }

    vector<bool> take(n, 1);
    for(int i = 0; i < del; i++) {
        take[order[i]] = 0;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(take[i]) ans.pb(i);
    }

    cout << s[ans[pos - 1]];
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
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
