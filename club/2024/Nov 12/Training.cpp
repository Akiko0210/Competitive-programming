#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if(l <= s && s <= r) {
            s++;
        }
    }
    cout << s << "\n";

    return 0;
}