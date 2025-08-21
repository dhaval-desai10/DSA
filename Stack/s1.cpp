#include <iostream>
using namespace std;
class stack
{
    int top;
    int size;
    int data;
    int *arr;

public:
    stack(int s)
    {
        top = -1;
        size = s;
        arr = new int[size];
    }
    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "stack is full " << endl;
        }
        else
        {
            top++;
            arr[top] = data;
            cout << "push : " << arr[top] << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack is empty " << endl;
        }
        else
        {
            cout << "pop element : " << arr[top] << endl;
            top--;
        }
    }   
  
};
int main()
{
    int size;
    cout << "size :";
    cin >> size;
    stack ss(size);
    ss.push(10);
    ss.push(20);
    ss.push(30);

    ss.pop();
    ss.pop();

    return 0;
}