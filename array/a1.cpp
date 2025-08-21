#include <iostream>
using namespace std;
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9};
    int n1 = (sizeof(arr1)) / 4;
    int n2 = sizeof(arr2) / 4;
    int n3 = n1 + n2;
    int arr1r[n1];
    int arr2r[n2];

    int arr3[n1];
    int i, j, k = 0, carry = 0;
    int val1 = 0;
    int val2 = 0;


    for (int i = 0; i < n1; i++)
    {
        if (i < n1)
        {
            val1 = arr1[i];
        }
        if (i < n2)
        {
            val2 = arr2[i];
        }
        int sum = val1 + val2 + carry;
        arr3[i] = sum % 10;
        carry = sum / 10;
    }
    arr3[n1] = carry;
    for (int i = 0; i <n1+1; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}