// Write a program to concatenate two doubly linked lists.

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
class linked_list{
    Node* first1;
    Node* last1;
    Node* first2;
    Node* last2;
    public:
    linked_list()
    {
        first1=NULL;
        last1 =NULL;

        first2=NULL;
        last2=NULL;
    }
    void insertatfront1(int value)
    {
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(first1==NULL)
        {
            first1=newnode;
            last1=newnode;
            
        }
        else
        {
            newnode->next=first1;
            first1->prev=newnode;
            first1=newnode;
        }
    }
   
    void insertatfront2(int value)
    {
        Node* newnode=new Node();
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(first2==NULL)
        {
            first2=newnode;
            last2=newnode;
        }
        else
        {
            newnode->next=first1;
            first2->prev=newnode;
            first2=newnode;
        }
    }
    void concatenate(linked_list insertatfront1,linked_list insertatfront2)
    {
        last1->next = first2;
        first2->prev = last1;
        delete last1;
        delete first2;
    }
    void display()
    {
        Node* temp = first1;
        while(temp->next!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }
  
};
int main()
{
    linked_list l1;
    linked_list l2;

    linked_list l;



    l1.insertatfront2(10);
    l1.insertatfront2(20);
    l1.insertatfront2(30);

    l2.insertatfront1(50);
    l2.insertatfront1(40);

    l.concatenate(l1,l2);

    l.display();



}