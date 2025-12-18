#include <bits/stdc++.h>

using namespace std;

bool isCorner(int x, int y) {
    return (x == 0 && (y == 0 || y == 2024)) || (x == 2024 && (y == 0 || y == 2024));
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cnt = isCorner(x1, y1) + isCorner(x2, y2);
    cout << 2 - cnt << "\n";

}