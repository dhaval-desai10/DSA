#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int l1[n1];
    int l2[n2];

    // Copy values to temporary arrays
    int mainarrayindex = start;
    for (int i = 0; i < n1; i++)
    {
        l1[i] = arr[mainarrayindex++];
    }
    mainarrayindex = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        l2[i] = arr[mainarrayindex++];
    }
    
    // Merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = start;
    while (index1 < n1 && index2 < n2)
    {
        if (l1[index1] < l2[index2])
        {
            arr[mainarrayindex++] = l1[index1++];
        }
        else
        {
            arr[mainarrayindex++] = l2[index2++];
        }
    }

    // Copy remaining elements of l1[], if any
    while (index1 < n1)
    {
        arr[mainarrayindex++] = l1[index1++];
    }

    // Copy remaining elements of l2[], if any
    while (index2 < n2)
    {
        arr[mainarrayindex++] = l2[index2++];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {10, 11, 13, 9, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}