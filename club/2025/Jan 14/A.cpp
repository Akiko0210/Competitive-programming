#include <iostream>

using namespace std;

int main() {

    int n;
    int x = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s; // "X++"
        cin >> s;
        if(s[1] == '+') {
            x++;
        } else {
            x--;
        }
    }

    cout << x << "\n";

    
    return 0;
}