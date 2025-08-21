#include <iostream>
using namespace std;

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Array sizes
    int maxLength = max(n1, n2) + 1; // One extra space for potential carry overflow

    // Arrays to store the reversed numbers
    int arr1r[n1];
    int arr2r[n2];
    int arr3[maxLength] = {0}; // Result array with potential carry space

    // Reverse arr1 into arr1r
    for (int i = 0; i < n1; i++) {
        arr1r[i] = arr1[n1 - 1 - i];
    }

    // Reverse arr2 into arr2r
    for (int i = 0; i < n2; i++) {
        arr2r[i] = arr2[n2 - 1 - i];
    }

    int carry = 0;
    for (int i = 0; i < maxLength - 1; i++) {
        int val1 = (i < n1) ? arr1r[i] : 0;
        int val2 = (i < n2) ? arr2r[i] : 0;
        int sum = val1 + val2 + carry;
        arr3[i] = sum % 10;
        carry = sum / 10;
    }
    arr3[maxLength - 1] = carry;

    // Print the resulting array in the correct order (ignore leading zeros)
    bool leadingZero = true;
    for (int i = maxLength - 1; i >= 0; i--) {
        if (arr3[i] == 0 && leadingZero) {
            continue;
        } else {
            leadingZero = false;
            cout << arr3[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
