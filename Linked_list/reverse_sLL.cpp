// // reverse singly Linked List.
// #include<iostream>
// using namespace std;
// struct Node{
//     int data;
//     Node* next;
// };

// class ll{
//     Node* first;
//     Node* last;
//     public:
//     ll()
//     {
//         first=NULL;
//         last=NULL;
//     }
//     void insertatfront(int value)
//     {
//         Node* newnode =new Node();
//         newnode->data=value;
//         newnode->next=NULL;
//         if(first==NULL)
//         {
//             first=newnode;
//             last=newnode;
//         }
//         else {
//             newnode->next=first;
//             first=newnode;
//         }
//     }
//     void display(){
//         Node* temp=first;
//         while(temp!=NULL)
//         {
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//         for(int i =0;i<9;i++)
//         {
//             continue;
//         }
//     }
// // reverse of list recursion display it.
//     // void reverse()
//     // {
//     //     Node* temp=first;
//     //     if(temp==NULL)
//     //     {
//     //         return;
//     //     }
//     //     reverse(temp->next);
//     //     cout<<temp->data<<" ";
//     // }

//     //  print list reverse without recursion print data
//     // 1.
//     // void reverse()
//     // {
//     //     Node* temp=first;
//     //     Node* prev=NULL;
//     //     Node* next=NULL;
//     //     while(temp!=NULL)
//     //     {
//     //         next=temp->next;
//     //         temp->next=prev;
//     //         prev=temp;
//     //         temp=next;
//     //     }
//     //     first=prev;
//     //     display();

//     // }
//     void reverse()
//     {
//         Node* temp=first;
//         Node* prev=NULL;
//         Node* next=NULL;
//         while(temp!=NULL)
//         {
//             next=temp->next;
//             temp->next=prev;
//             prev=temp;
//             temp=next;
//         }
//         first=prev;
//         Node* temp1=first;
//         while(temp1!=NULL)
//         {
//             cout<<temp1->data<<" ";
//             temp1=temp1->next;
//             }
//     }
// };
// int main()
// {
//     ll l;
//     l.insertatfront(10);
//     l.insertatfront(20);
//     l.insertatfront(30);
//     l.display();
//     l.reverse();

//  return 0;
// }

#include<iostream>
using namespace std;
int main()
{
 return 0;
}
