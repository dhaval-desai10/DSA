// #include <iostream>
// using namespace std;
// int partition(int arr[], int start, int end)
// {
//     int pivot = arr[start];
//     int count = 0;
//     for (int i = start + 1 ; i <= end; i++)
//     {
//         if (arr[i] <= pivot)
//         {
//             count++;
//         }
//     }
//     int pivotindex = start + count;
//     swap(arr[start],arr[pivotindex]);
//     int i = start;
//     int j = end;
//     while(i<pivotindex && j>pivotindex)
//     {
//         if(arr[i] < pivot)
//         {
//             i++;
//         }
//         else if(arr[j] > pivot)
//         {
//             j--;
//         }
//         else{
//             swap(arr[i],arr[j]);
//             i++;
//             j--;
//         }
//     }
//     return pivotindex;

// }
// void quicksort(int arr[], int start, int end)
// {
//     if (start >= end)
//     {
//         return;
//     }
//     int p = partition(arr, start, end);
//     quicksort(arr, start, p - 1);
//     quicksort(arr, p + 1, end);
// }
// int main()
// {
//     int arr[5] = {1, 3, 5, 4, 7};
//     int n = 5;
//     quicksort(arr, 0, n - 1);
//     cout << "sorted array is : " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class PriorityQueue {
// private:
//     int *arr;
//     int capacity;
//     int size;

// public:
//     PriorityQueue(int cap) {
//         capacity = cap;
//         arr = new int[capacity];
//         size = 0;
//     }

//     ~PriorityQueue() {
//         delete[] arr;
//     }

//     void enqueue(int value) {
//         if (size == capacity) {
//             cout << "Priority Queue is full" << endl;
//             return;
//         }

//         // Insert the new element in the correct position to maintain the order
//         int i;
//         for (i = size - 1; (i >= 0 && arr[i] < value); i--) {
//             arr[i + 1] = arr[i];
//         }
//         arr[i + 1] = value;
//         size++;
//         cout << value << " is enqueued" << endl;
//     }

//     void dequeue() {
//         if (size == 0) {
//             cout << "Priority Queue is empty" << endl;
//             return;
//         }

//         cout << arr[0] << " is dequeued" << endl;
//         for (int i = 0; i < size - 1; i++) {
//             arr[i] = arr[i + 1];
//         }
//         size--;
//     }

//     int peek() {
//         if (size == 0) {
//             cout << "Priority Queue is empty" << endl;
//             return -1;
//         }
//         return arr[0];
//     }

//     bool isEmpty() {
//         return size == 0;
//     }

//     bool isFull() {
//         return size == capacity;
//     }
// };

// int main() {
//     PriorityQueue pq(5);

//     pq.enqueue(30);
//     pq.enqueue(20);
//     pq.enqueue(50);
//     pq.enqueue(40);
//     pq.enqueue(10);

//     cout << "Top element is: " << pq.peek() << endl;

//     pq.dequeue();

//     pq.dequeue();

//     cout << "Top element is: " << pq.peek() << endl;

//     return 0;
// }

// find  all permutatons of given array
#include <bits/stdc++.h>
using namespace std;
void printarray(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
void generates(vector<int> &arr, int start)
{
    if (start == arr.size() - 1)
    {
        printarray(arr);
        return;
    }
    for (int i = start; i < arr.size(); i++)
    {
        swap(arr[start], arr[i]);
        generates(arr, start + 1);
        swap(arr[start], arr[i]);
    }
}
int main()
{
    vector<int> arr = {1, 2, 3};
    generates(arr, 0);
    return 0;
}
