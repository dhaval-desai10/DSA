#include<iostream>
using namespace std;
class queues{
    int rear,front,size;
    int arr[5];
    public:
    queues(){
        rear=-1;
        front=-1;
        size=5;
    }
    void enqueue(int data)
    {
            if((rear+1)%size==front) 
        {
            cout<<"its full"<<endl;
        }
        else if(front==-1)
        {
            rear=front=0;
            arr[front]=data;
        }
        else if(rear==size-1)
        {
            rear=0;
            arr[rear]=data;
        }
        else{
            // rear=(rear+1)%size;
            rear++;
            arr[rear]=data;
        }
        cout<<"pushed :"<<arr[rear]<<endl;
    }
    void dequeue()
    {
        if(front==-1)
        {
            cout<<"its empty "<<endl;
        }
        else{
            cout<<arr[front]<<" is poped:  "<<endl;
            if(front==rear)
            {
                front=rear=-1;
            }
            else if(front==size-1)
            {
                front=0;
            }
            else{
                front++;
            }
        }
    }

};
int main()
{
    queues q1;
    q1.enqueue(20);
    q1.enqueue(30);
    q1.dequeue();
    q1.dequeue();
 return 0;
}