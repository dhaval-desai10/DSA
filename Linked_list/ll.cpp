#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class linked_list{
    Node* first;
    Node* last;
    public :
    linked_list()
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
        }
        else {
            newnode->next=first;
            first=newnode;
        }
    }
    void insretatend(int value)
    { Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        if(first==NULL)
        {
            first=newnode;
            last=newnode;
        }
        else {
            last->next=newnode;
            last=newnode;
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
        else {
            Node* temp=first;
            for(int i=0;i<position-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
       
    }
    void display()
    {
        Node* temp=first;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }



};
int main()
{
   linked_list ll;
    ll.insertatfront(10);
    ll.insertatfront(20);
    ll.insertatfront(30);

    ll.insretatend(60);

    ll.insertatposition(2,100);
    ll.display();



}