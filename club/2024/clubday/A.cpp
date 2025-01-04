#include <iostream>
#include <algorithm>

using namespace std;

int test(int arr[], int start, int end);
int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n-1; i++) {
        cin >> arr[i];

    }

    sort(arr, arr + n);

    cout << test(arr,0,n) << endl;

    return 0;
}

int test(int arr[], int start, int end) {
    int n;
    if (start == end) {
        return start;
    }
    else if (arr[(start + (end-start)/2) - 1] == (end-start)/2) {
        n = test(arr,(end-start)/2 + 1,end);
    }
    else {
        n = test(arr,start,(end-start)/2);
    }
    return n;
}