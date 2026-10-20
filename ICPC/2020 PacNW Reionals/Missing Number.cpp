#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        string t = to_string(i);
        int len = t.size();
        if(t == s.substr(cur, len)) {
            cur += len;
        } else {
            cout << i << "\n";
            return 0;
        }
    }


    return 0;
}