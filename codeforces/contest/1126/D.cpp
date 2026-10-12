#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define pb push_back
#define pii pair<ll, ll>
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
    int n, m, k;
    cin >> n >> m >> k;
    // vector<pii> a(n);
    vector<pii> ranges;
    ll lastfree = 1;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        // cin >> a[i].ff >> a[i].ss;
        // debug(x, y);
        ranges.pb({x - lastfree, 0});
        lastfree = y + 1;
        ranges.pb({lastfree - x, 1});
    }
    ranges.pb({1e15, 0});

    
    /*
    we need to find s such that [s, s + m - 1] has EXACTLY k intersect with the segments. 
    that is also m - k free slots.
    free [] free [] free []
    
    segments:
    1. start at free and end at free.
    2. start at infected and end at free.
    3. start at free and end at infected.
    4. start at infected and end at infected.
    */
   
    queue<pii> q;
    ll curfree = 0, curinfected = 0, startpos = 1;
    for(auto [len, side] : ranges) {
        // debug(len, side);
        // if(curfree + (side == 0 ? len : 0) < m - k || curinfected + (side == 1 ? len : 0) < k) {
            
        // }
        ll addinf = 0, addfree = 0;
        if(side == 1) {

            /*
            infected range [curinfected, curinfected + len]

            if front side = 0:
            [curfree - frontfree, curfree] has m - k
            */
            addinf = len;
        } else {
            addfree = len;
        }

        bool can = false;
        while(!q.empty()) {
            // debug("here");
            auto [flen, fside] = q.front();
            if(fside == 0) {
                // free range: [curfree - flen, curfree + addfree]
                if(curfree - flen + addfree >= m - k) {
                    curfree -= flen;
                    startpos += flen;
                    q.pop();
                    continue;
                }

                if(curfree + addfree < m - k) {
                    // we need more. we don't have enough free.
                    can = false;
                    break;
                }

                /*
                m - k is in range [curfree - flen + addfree, curfree + addfree]
                */ 
                
                if(side == 0) {
                    // if my last side is 0, 1 is enclosed
                    // my curinfected has to exactly k
                    if(curinfected == k) {
                        can = true;
                        // startpos + flen
                        ll withoutfront = curfree - flen + addfree;
                        // if(curfree - flen + addfree >= m - k) {
                        //     cout << startpos + flen << "\n";
                        // } else {
                            cout << startpos + flen - (m - k - withoutfront) << "\n";
                        // }

                        return;
                    }
                    // continue;
                } else {
                    // infected: [curinfected, curinfected + addinf]
                    // free : [curfree - flen, curfree]
                    if(curinfected <= k && curinfected + addinf >= k) {
                        cout << startpos + curfree - (m - k) << "\n";
                        return;
                    }
                    // continue;
                }
            } else {
                if(curinfected + addinf - flen >= k) {
                    curinfected -= flen;
                    startpos += flen;
                    q.pop();
                    continue;
                }

                if(curinfected + addinf < k) {
                    // we need more. we don't have enough infected.
                    can = false;
                    break;
                }

                /*
                k is in range [curinfected + addinf - flen, curinfected + addinf]
                */ 

                if(side == 1) {
                    // if my last side is 1, 0 is enclosed
                    // my curinfected has to exactly k
                    if(curfree == m - k) {
                        can = true;
                        // startpos + flen
                        ll withoutfront = curinfected - flen + addinf;
                        // if(curinfected - flen + addinf >= k) {
                        //     cout << startpos + flen << "\n";
                        // } else {
                        cout << startpos + flen - (k - withoutfront) << "\n";
                        // }

                        return;
                    }
                    // continue;
                } else {
                    // free : [curfree, curfree + addfree]
                    // infected: [curinfected - flen, curinfected]
                    if(curfree <= m - k && curfree + addfree >= m - k) {
                        cout << startpos + curinfected - (k) << "\n";
                        return;
                    }
                    // continue;
                }
            }
        
            break;
        }

        if(k == m && q.empty()) {
            if(side == 1 && len >= k) {
                cout << startpos << "\n";
                return;
            }
        }

        if(k == 0 && q.empty()) {
            if(side == 0 && len >= m) {
                cout << startpos << "\n";
                return;
            }
        }

        q.push({len, side});
        curfree += addfree;
        curinfected += addinf;
    }

    cout << "-1\n";
}

int main() {
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

