#include <bits/stdc++.h>
using namespace std;

bool canweplacecow(const vector<int>& arr, int dist, int cows) {
    int count = 1, last = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
        }
    }
    return count >= cows;
}

int main() {
    vector<int> arr = {0, 3, 4, 7, 9, 10}; // must be sorted
    int n = arr.size();
    int cows = 4;
    int mini = arr[0];
    int maxi = arr[n - 1];

    // Linear search (brute-force)
    int ans_linear = 0;
    for (int i = 1; i <= maxi - mini; i++) {
        if (canweplacecow(arr, i, cows)) {
            ans_linear = i;
        }
    }
    cout << "Linear search answer : " << ans_linear << endl;

    // Binary search (optimal)
    int low = 1, high = maxi - mini, ans_binary = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canweplacecow(arr, mid, cows)) {
            ans_binary = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Binary search answer : " << ans_binary << endl;
    return 0;
}