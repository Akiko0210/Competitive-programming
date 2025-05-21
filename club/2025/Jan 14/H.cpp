#include <iostream>

using namespace std;

int main() {
    int n, cur = 0, capacity = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cur -= a;
        cur += b;
        if(cur > capacity) {
            capacity = cur;
        }
    }
    cout << capacity << "\n";
    return 0;
}