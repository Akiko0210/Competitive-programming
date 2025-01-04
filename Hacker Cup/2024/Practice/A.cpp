#include <bits/stdc++.h>

using namespace std;

void printans(int t, bool b) {
    cout << "Case #" << t << ": " << (b ? "YES\n" : "NO\n");
}

bool solve() {
    long long n, k;
    cin >> n >> k;
    vector<long long> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    if(n == 1) 
        return s[0] <= k;
    
    sort(s.begin(), s.end());
    // s[0]
    // 2 -> 1, 3 -> 3, 4 -> 5
    return s[0] * (n * 2 - 3) <= k;
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        printans(i, solve());
    }

    return 0;
}
