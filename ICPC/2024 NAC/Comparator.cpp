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
const int K = 10;
const int N = (1 << K);

int prec(char c) {
    if(c == '^') return 0;
    if(c == '|') return 1;
    if(c == '&') return 2;
    if(c == '=') return 3;
    return 4;
}

bool eval(int x, int y, string& expr) {
    string st = "";
    for(char c : expr) {
        if(c == '=' || c == '|' || c == '^' || c == '&' || c == '(' || c == '!') {
            st += c;
            continue;
        }
        
        bool val;
        if(c == ')') {
            // roll back till (
            char last = st.back();
            st.pop_back();
            st.pop_back(); // assume it's (
            val = last - '0';
            // st.push_back(last);
            // continue;
        } else {
            if(c == 'x') val = x;
            else if(c == 'y') val = y;
            else val = c - '0';
        }

        
        while(!st.empty() && st.back() != '(') {
            // !
            if(st.back() == '!') {
                val = !val;
                st.pop_back();
                continue;
            }
    
            // =
            if(st.back() == '=') {
                st.pop_back();
                char last = st.back();
                st.pop_back();
                val = ((last - '0') == val);
                continue;
            }

            if(st.back() == '^') {
                st.pop_back();
                char last = st.back();
                st.pop_back();
                val = ((last - '0') ^ val);
                continue;
            }

            if(st.back() == '|') {
                st.pop_back();
                char last = st.back();
                st.pop_back();
                val = ((last - '0') | val);
                continue;
            }

            if(st.back() == '&') {
                st.pop_back();
                char last = st.back();
                st.pop_back();
                val = ((last - '0') & val);
                continue;
            }
        }
        st += ('0' + val);
    }
    return st[0] - '0';
}

bool eval1(int x, int y, string& expr) {
    // debug(x, y, expr);
    string st = "";

    auto execute = [&] () {
        int n = st.size();
        int a = st[n - 3] - '0';
        int b = st[n - 1] - '0';
        char op = st[n - 2], c;
        if(op == '=') {
            c = '0' + (a == b);
        }
        if(op == '&') {
            c = '0' + (a & b);
        }
        if(op == '|') {
            c = '0' + (a | b);
        }
        if(op == '^') {
            c = '0' + (a ^ b);
        }
        st.pop_back();
        st.pop_back();
        st.pop_back();
        st += c;
    };

    for(char c : expr) {
        if(c == 'x' || c == 'y' || c == '0' || c == '1' || c == ')') {
            int val;
            if(c == ')') {
                // can assume st.back() is 0 or 1
                int n = st.size();
                while(n >= 2 && st[n - 2] != '(') {
                    execute();
                    n = st.size();
                }
                val = st.back() - '0';
                st.pop_back();
                st.pop_back(); // remove (
            } else {
                if(c == 'x') val = x;
                else if(c == 'y') val = y;
                else val = c - '0';
            }

            while(!st.empty() && st.back() == '!') {
                st.pop_back();
                val = !val;
            }
            st += '0' + val;
            continue;
        }

        if(c == '(' || c == '!') {
            st += c;
            continue;
        }
        int n = st.size();
        while(n >= 3 && st[n - 2] != '(' && prec(st[n - 2]) >= prec(c)) { 
            execute();
            n = st.size();
        }
        st += c;
    }

    while(st.size() > 1) {
        execute();
    }
    // debug(st);

    return st[0] - '0';
}

int main() {
    FAST
    int n, k;
    cin >> n >> k;
    int dp[K * K][4];
    bitset<N> mat[N];
    memset(dp, -1, sizeof(dp));
    // memset(mat, -1, sizeof(mat));

    vector<bool> c(n);
    for(int i = 0; i < n; i++) {
        int a, b, r;
        string expr;
        cin >> a >> b >> expr >> r;
        a--;
        b--;
        c[i] = r;
        for(int x = 0; x < 2; x++) {
            for(int y = 0; y < 2; y++) {
                int ind1 = a * k + b;
                int ind2 = x * 2 + y;
                if(eval1(x, y, expr) && dp[ind1][ind2] == -1) {
                    dp[ind1][ind2] = i;
                }
            }
        }
    }

    bool defaultVal;
    cin >> defaultVal;

    for(int x = 0; x < (1 << k); x++) {
        for(int y = 0; y < (1 << k); y++) {
            int mn = INF;
            for(int a = 0; a < k; a++) {
                for(int b = 0; b < k; b++) {
                    int b1 = ((x & (1 << a)) ? 1 : 0);
                    int b2 = ((y & (1 << b)) ? 1 : 0);
                    int ind1 = a * k + b;
                    int ind2 = b1 * 2 + b2;
                    if(dp[ind1][ind2] != -1) {
                        mn = min(dp[ind1][ind2], mn);
                    }
                }
            }
            if(mn == INF) {
                mat[x][y] = defaultVal;
            } else {
                mat[x][y] = c[mn];
            }
        }
    }
    int res[3] = {0, 0, 0};
    // reflexive
    for(int i = 0; i < (1 << k); i++) {
        if(mat[i][i]) res[0]++;
    }
    // symmetric
    for(int i = 0; i < (1 << k); i++) {
        for(int j = 0; j < (1 << k); j++) {
            if((mat[i][j] == mat[j][i]) && (mat[i][j] == 1)) {
                res[1]++;
            }
        }
    }
    // transitive
    
    for(int i = 0; i < (1 << k); i++) {
        for(int j = 0; j < (1 << k); j++) {
            if(mat[i][j]) {
                // i < j
                res[2] += (~mat[i] & mat[j]).count();
            }
        }
    }

    cout << res[0] << " " << res[1] << " " << res[2] << "\n";

    // for(int )

    return 0;
}

/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

