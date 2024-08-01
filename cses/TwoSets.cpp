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

int main() {
    ll n, sum;
    cin >> n;
    sum = n * (n + 1) / 2;

    if(sum & 1) {
        cout << "NO\n";
        return 0;
    }

    sum /= 2;
    cout << "YES\n";
    vector<int> s1, s2;
    for(int i = n; i > 0; i--) {
        if(sum >= i) {
            sum -= i;
            s1.pb(i);
        } else {
            s2.pb(i);
        }
    }   
    cout << s1.size() << "\n";
    for(int x : s1) {
        cout << x << " ";
    }
    cout << "\n" << s2.size() << "\n";
    for(int x : s2) {
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

