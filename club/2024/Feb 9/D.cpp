#include <iostream>

using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n, l = -1, r = -2;
        string s;
        cin >> n >> s;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') {
                if(l == -1) l = i;

                r = i;
            }
        }
        cout << r - l + 1 << "\n";
    }
    return 0;
}