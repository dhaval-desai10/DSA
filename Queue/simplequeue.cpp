#include<iostream>
using namespace std;
class queues {
    int front ;
   int rear,n;
   int *arr;
// simple enqueue
public:
queues(int size)
{
   front=-1;
   rear=-1;
    n=size;
   arr=new int[n];

}
void enqueue(int data)
{
  
   if(rear==n-1)
   {
      cout<<"its full "<<endl;

   }
   else {
      rear++;
   arr[rear]=data;
   cout<<"data inserted "<< arr[rear] <<endl;
   }

}
void dequeue()
{

    if(front==rear)
    cout<<"its empty"<<endl;
    else{
        front++;
        cout<<"data deleted "<<arr[front]<<endl;    

    }

}
};
int main()
{
   queues qq(5);
   qq.enqueue(1);
   qq.enqueue(2);
   qq.enqueue(3);
   qq.enqueue(4);
   qq.enqueue(5);
   qq.enqueue(5);
   qq.dequeue();
   qq.dequeue();
   


 return 0;
}