#include <iostream>
using namespace std;
int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }


    }
    
    // place pivot at its right position

    int pivotindex = s + count;

    swap(arr[pivotindex], arr[s]);

    // int temp = arr[s];
    // arr[s] = arr[pivotindex];
    // arr[pivotindex] = temp;

    // left and right part sorting
    int i = s;
    int j = e;
    while (i < pivotindex && j > pivotindex)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else
        {
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
            // i++;
            // j--;
            swap(arr[i], arr[j]); 
            i++;
            j--;
        }
    }
    return pivotindex;
}
void quicksort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // recursive case partition
    int p = partition(arr, s, e);

    // left part sortint
    quicksort(arr, s, p - 1);

    // right part sorting
    quicksort(arr, p + 1, e);   
}
int main()
{
    int arr[10] = {2, 4, 1, 6, 9, 9, 9, 9, 9, 10};
    int n = 10;
    quicksort(arr, 0, n - 1);
    cout << "Sorted array is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    cout << endl;

    return 0;
}

