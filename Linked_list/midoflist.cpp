#include<iostream>
using namespace std;
struct  Node
{
    int data;
    Node* next;
};
class ll{
    Node* first;
    Node* last;
    public:
    ll()
    {
        first = NULL;
        last = NULL;
    }
    void insertatfront(int data)
    {
        Node* newnode = new Node();
        newnode->data = data;
        newnode->next = NULL;
        if(first == NULL)
        {
            first = newnode;
            last = newnode;
        }
        else {
            newnode->next = first;
            first = newnode;
        }
    }
    int count=0;
    void display()
    {
        Node* temp = first;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
            count++;
        }
        cout<<endl;
        cout<<"Length Of List Is : "<<count<<endl;
    }
    void mid_of_list()
    {
        Node* temp = first;
         int ans = (count/2);
    int count = 0;
    while(count<ans){
        
        temp = temp->next;
        count++;
    }
    cout<<temp->data<<endl;
    

    }
};

int main()
{
    ll l;
    l.insertatfront(10);
    l.insertatfront(40);
    l.insertatfront(30);
    l.insertatfront(50);

    // l.insertatfront(60);

    

    l.display();

    

    l.mid_of_list();

 return 0;
}