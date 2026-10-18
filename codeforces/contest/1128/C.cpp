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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for(int &x : a) {
        cin >> x;
        sum += x;
    }

    if(sum % 2 == 0) {
        cout << "Moggity\n";
        return;
    }

    // sum is odd.
    if(n == 2 || (n == 3 && a[0] % 2 == 1 && a[1] % 2 == 1 && a[2] % 2 == 1)) {
        cout << "Larpity\n";
        return;
    }

    cout << "Moggity\n";

    // moggity has to leave the sum odd and leave more than 1 element.
    // if there is at least 1 even element, moggity wins automatically.
    /*
    if the whole array has only odd elements, moggity leave at least 3 elements.
    Then if larpity choose:
    1 element, moggity wins, 
    2 elements moggity wins, 
    and can't choose 3 elements.
    
    
    */ 
    
    // Larpity

}

int main() {
    FAST
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
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

