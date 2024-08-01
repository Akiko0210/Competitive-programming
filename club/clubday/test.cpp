#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int num;
    int arr [200000];
    for(int i = 0; i < n-1; i++) {
        cin >> num;
        arr[i] = num;
    }

    sort(arr, arr + n-1);

    for(int i = 1; i < n; i++) {
        if(i != arr[i-1]) {
            cout << i;
            return 0;
        }
    }
    cout << n;
    return 0;
}