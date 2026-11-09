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
    cout << "Enter the intial pattern: \n";
    vector<string> mat(2);
    for(int i = 0; i < 2; i++) {
        cin >> mat[i];
    }

    auto apply = [&](vector<string>& newmat) {
        int n = mat.size();
        vector<string> res(n * 2, string(n * 2, 'o'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 'X') {
                    for(int di = 0; di < 2; di++) {
                        for(int dj = 0; dj < 2; dj++) {
                            res[i * 2 + di][j * 2 + dj] = newmat[di][dj];
                        }
                    }
                }
            }
        }
        mat = res;
    };

    while(true) {
        cout << "What pattern to apply?\n";
        vector<string> applymat(2);
        cin >> applymat[0] >> applymat[1];
        apply(applymat);

        cout << "\nresult:\n";
        for(auto row : mat) {
            cout << row << "\n";
        }
        cout << "\n\n";
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

