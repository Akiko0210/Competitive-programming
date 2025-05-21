#include <iostream>
#include <cctype>

using namespace std;

int main() {
    /*
    s1, s2
    s1 < s2 -> -1
    s1 > s2 -> 1
    s1 == s2 -> 0

    s1 = "ABCD"
       i
    s1[0] = 'A'
    s1[1] = 'B'
    s1[2] = 'C'
    s2[3] = 'D'
    there is no s1[4]

    */ 
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(); // n = s2.size()
    for(int i = 0; i < n; i++) {
        s1[i] = toupper(s1[i]);
        s2[i] = toupper(s2[i]);
    }
    if(s1 < s2) {
        cout << "-1\n";
    } else if (s1 > s2) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
    return 0;
}