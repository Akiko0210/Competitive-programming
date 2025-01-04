#include <iostream>

using namespace std;

int main() {
    int a[6]; // occupying location of 10 consecutive integers in the array
    int *pa = &a[0]; // noting the location of the very first element of the array
    for(int i = 0; i < 6; i++) {
        pa = &a[i];
        cout << pa << endl; // printing the location that I noted.
    }
    return 0;
}
