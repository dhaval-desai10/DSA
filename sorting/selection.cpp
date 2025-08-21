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
    
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; 
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; 
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

// Print the sorted array
for (int x = 0; x < n; x++)
{
    cout << arr[x] << " ";
}
cout << endl;

}