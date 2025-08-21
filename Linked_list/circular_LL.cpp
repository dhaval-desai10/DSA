#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class circular_ll{
    
    Node* first;
    Node* last;
    public :
    circular_ll()       
    {
        first=NULL;
        last=NULL;
    }
    void insertatfront(int value)
    {
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if(first==NULL)
        {
            first=newnode;
            last=newnode;
            last->next=first;

        }
        else {
            newnode->next=first;
            first=newnode;
            last->next=first;

        }
    }
    void insertatlast(int value)
    {
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if(first==NULL)
        {
            first=newnode;
            last=newnode;
            last->next=first;
            
        }
        else {
            last->next=newnode;
            last=newnode;
            last->next=first;
        }
    }
    void insertatposition(int position,int value)
    {
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if(position==0)
        {
            insertatfront(value);
        }
        else
        {
            Node* temp=first;
            for(int i=1;i<position-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    void countnode()
    {
        Node* temp=first;
        int count=1;
        while(temp->next!=first)
        {
            count++;
            temp=temp->next;
        }
        cout<<"number of nodes in circular linked list : "<<count<<endl;
    }

    void deletefromfront()
    {
        Node* temp=first;
        first=first->next;
        last->next=first;
        delete temp;
    }

   
    void deletefromend()
    {
        Node* temp=first;
        while(temp->next!=last)
        {
            temp=temp->next;
        }
        temp->next=first;
        delete last;
        last=temp;
    }
    void deletefromposition(int position)
    {
        Node* temp=first;
        for(int i=1;i<position-1;i++)
        {
            temp=temp->next;
        }
        Node* temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }
     void display()
    {
        Node* temp=first;
        while(temp->next!=first)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    circular_ll c;
    c.insertatfront(10);
    c.insertatfront(20); 
    c.insertatfront(30);

    // c.insertatlast(40);
    // c.insertatlast(50);

    c.display();

    c.deletefromfront();
    c.display();

    c.countnode();
 return 0;
}