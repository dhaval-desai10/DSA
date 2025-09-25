#include <iostream>
using namespace std;
class queues
{
   int front;
   int rear, n;
   int *arr;
   // simple enqueue
public:
   queues(int size)
   {
      front = -1;
      rear = -1;
      n = size;
      arr = new int[n];
   }
   void enqueue(int data)
   {

      if (rear == n - 1)
      {
         cout << "its full " << endl;
      }
      else
      {
         rear = ((rear + 1) % (n - 1)) + 1;
         arr[rear] = data;
         cout << "data inserted " << arr[rear] << endl;
      }
   }
   void dequeue()
   {

      if (front == rear)
         cout << "its empty" << endl;
      else
      {
         front = ((front + 1) % (n - 1)) + 1;
         cout << "data deleted " << arr[front] << endl;
      }
   }
};

class Node
{
public:
   int data;
   Node *next;
   Node(int val)
   {
      data = val;
      next = nullptr;
   }
};

class queue_ll
{
   Node *start;
   Node *end;
   int size;

public:
   queue_ll()
   {
      start = nullptr;
      end = nullptr;
      size = 0;
   }
   void enqueue(int data)
   {
      Node *newNode = new Node(data);
      cout<<"pushed : "<<newNode->data<<endl;
      if (start == nullptr)
      {
         start = newNode;
         end = newNode;
      }
      else {
         end->next = newNode;
         end = newNode;
      }
      size++;
   }
   void dequeue(){
      if(start == nullptr){
         cout<<"nothing has to poped "<<endl;
         return;
      }
      cout<<"poped : "<<start->data<<endl;
      Node* temp = start;
      start = start->next;
      delete temp;
      if(start == nullptr){
         end = nullptr;
      }
      size--;
   }
};

int main()
{
   // queues qq(5);

   queue_ll qq;
   qq.enqueue(1);
   qq.enqueue(2);
   qq.enqueue(3);
   qq.enqueue(4);
   // qq.enqueue(5);
   // qq.enqueue(5);
   qq.dequeue();
   qq.dequeue();

   return 0;
}