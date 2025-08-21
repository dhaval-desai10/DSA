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
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)     
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}