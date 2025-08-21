#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
root = new Node(data);
    

    cout << "Enter the data to insert at left of " << data << ": " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data to insert at right of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

// level order traversal
void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// inorder (LNR)
void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preordered (NLR)

void preorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// postorder (LRN)

void postorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//  void insert nodes in tree 


// build from level order traversal

Node *buildfromlevelorder(Node *root)
{
    queue<Node *> q;
    
    int data;
    cin >> data;
    root = new Node(data);

    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter  left " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);

        }
        cout << "Enter right  " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);

        }
      
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // cout << "printing levelorder " << endl;

    // levelorder(root);

    // buildfromlevelorder(root);
    levelorder(root);

    // cout<<"inorderd traversal "<<endl;
    // inorder(root);
    // cout<<endl;
    // cout<<"preorder traversal : "<<endl;
    // preorder(root);
    // cout<<endl;
    // cout<<"postorder tarversal "<<endl;
    // postorder(root);

    
}








