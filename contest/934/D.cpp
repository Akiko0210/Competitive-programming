#include <bits/stdc++.h>
#define ll long long
typedef unsigned long long ull;
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

int gen_base(int before, int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed ^ ull(new ull));
    std::uniform_int_distribution<int> dist(before+2, after-1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
}

struct PolyHash {
    static const int mod = (int)1e9+123; 
    std::vector<int> pow1;        
    std::vector<ull> pow2;     
    static int base;                    
 
    static inline int diff(int a, int b) { 
        return (a -= b) < 0 ? a + mod : a;
    }
 
    std::vector<int> pref1; 
    std::vector<ull> pref2; 
 
    PolyHash(const std::string& s)
    {
        assert(base < mod);
        const int n = s.size(); 
        pow1.resize(n + 1, 1);
        pow2.resize(n + 1, 1);
        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pow1[i] = 1LL * pow1[i - 1] * base % mod;
            pow2[i] = 1LL * pow2[i - 1] * base;
        }
        for (int i = 0; i < n; ++i) { 
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
        // cout << "here\n";
    }
 
    inline std::pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return std::make_pair(hash1, hash2);
    }
};
int PolyHash::base((int)1e9+7);    
// std::vector<int> PolyHash::pow1{1};
// std::vector<ull> PolyHash::pow2{1};



void solve() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<vector<vector<int> > > cnt(n, (vector<vector<int> > (2, vector<int> (26, 0))));
    for(int i = 0; i < n; i++) {
        if(i > 0) cnt[i] = cnt[i - 1];
        
        cnt[i][i & 1][s[i] - 'a']++;
    }
    PolyHash hash(s);
    // cout << "here\n";
    string t = s;
    reverse(t.begin(), t.end());
    PolyHash rHash(t);

    while(q--) {
        int l, r;
        cin >> l >> r;
        r--, l--;
        // debug(l, r);

        vector<int> odd = cnt[r][1], even = cnt[r][0];
        if(l > 0) {
            for(int i = 0; i < 26; i++) {
                odd[i] -= cnt[l - 1][1][i];
                even[i] -= cnt[l - 1][0][i];
            }
        }
        // for(int x : odd) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        // for(int x : even) {
        //     cout << x << " ";
        // }
        // cout << "\n";
        bool isAllBad = true;
        bool once = false;
        for(int i = 0; i < 26 && isAllBad; i++) {
            if(!odd[i] && !even[i]) continue;
            if(!once && odd[i] && even[i]) {
                once = true;
                continue;
            };

            isAllBad = false;
        }
        // debug(isAllBad);
        if(isAllBad) {
            cout << "0\n";
            continue;
        }

        bool isOddBad = true;
        once = false;
        for(int i = 0; i < 26 && isOddBad; i++) {
            // debug(odd[i], once);
            if(!odd[i]) continue;
            if(odd[i] && !once) {
                once = true;
                continue;
            }
            isOddBad = false;
        }
        // debug(isOddBad);
        once = false;
        for(int i = 0; i < 26 && isOddBad; i++) {
            if(!even[i]) continue;
            if(even[i] && !once) {
                once = true;
                continue;
            }
            isOddBad = false;
        }
        ll len = r - l + 1, ans = len * (len + 1) / 2;
        // debug(isOddBad);
        if(isOddBad) {
            ll k = (len + 1) / 2;
            ans -= k * k;
            cout << ans << "\n";
            continue;
        }
        int rl = n - 1 - l, rr = n - 1 - r;
        if(hash(l, len) == rHash(rr, len)) {
            ans -= len;
        }
        cout << ans - 1 << "\n";
    }

}

int main() {
    FAST
    PolyHash::base = gen_base(256, PolyHash::mod);
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

