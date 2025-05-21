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

class Union {
    private:
        int comp;
        unordered_map<int, int> p, s;
    public:
        Union() {
            comp = 0;
        }

        int find(int a) {
            if(p.find(a) == p.end()) {
                comp++;
                s[a] = 1;
                return p[a] = a;
            }
            
            if(p[a] == a) 
                return a;
            
            return p[a] = find(p[a]);
        }
        void merge(int a, int b) {
            int para = find(a), parb = find(b);
            if(para == parb) return;

            if(s[para] < s[parb]) {
                swap(para, parb);
            }
            // para swallow parb
            comp--;
            p[parb] = para;
            s[para] += s[parb];
        }

        int size() {
            return comp;
        }

};

const int N = 1e6;
vector<int> p(N + 1, 1);
void sieve() {
    for(int i = 2; i <= N; i++) {
        if(p[i] == 1) {
            for(int j = i; j <= N; j += i) {
                if(p[j] == 1) {
                    p[j] = i;
                }
            }
        }
    }
}

void solve() {
    /*
    1 2 3 4
    4 1 2 3
    3 4 1 2
    2 3 4 1

    man_dis(pos[a], pos[b]) <= k
    gcd(a, b) > 1
    
    */
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for()

    
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

