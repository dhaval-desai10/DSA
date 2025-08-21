#include <stdio.h>

 

void func(int arr[], int size) {

    for (int i = 0; i < size; i++) {

        arr[i] += 5;

    }

}

 

int main() {

    int arr[] = {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);

    func(arr, size);

    for (int i = 0; i < size; i++) {

        printf("%d ", arr[i]);

    }

    return 0;




}