#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "size of an array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }

    // Print the sorted array
    for (int x = 0; x < n; x++)
    {
        cout << arr[x] << " ";
    }
    cout << endl;
}