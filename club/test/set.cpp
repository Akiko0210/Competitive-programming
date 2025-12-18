#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s; // balanced binary search tree.
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    for(int x : s) {
        cout << x << " ";
    }
    cout << "\n";


    return 0;
}
