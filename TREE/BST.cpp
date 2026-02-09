
// BST
#include <iostream>
#include <queue>

#include <stack>
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

Node *insertintobst(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        // right part insertion

        root->right = insertintobst(root->right, d);
    }
    else if (d < root->data)
    {
        // left part insertion

        root->left = insertintobst(root->left, d);
    }
    return root;
}

void takeinput(Node *&root)
{
    int data;

    cin >> data;
    while (data != -1)
    {
        insertintobst(root, data);
        // insert data into BST
        cin >> data;
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
    // if (root == NULL)
    // {
    //     return;
    // }
    // cout << root->data << " ";

    // preorder(root->left);
    // preorder(root->right);

    // // iterative
    vector<int> ans;
    if (root == nullptr)
    {
        return;
    }
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->data);
        if (root->right != nullptr)
        {
            st.push(root->right);
        }
        if (root->left != nullptr)
        {
            st.push(root->left);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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

void levelorder(Node *root)
{
    if (root == NULL)
        return;

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

bool searchnumber(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    if (root->data > x)
    {
        return searchnumber(root->left, x);
    }
    else
    {
        return searchnumber(root->right, x);
    }
}

// min value of Node in BST
Node *minvaluebst(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)

    {
        temp = temp->left;
    }
    return temp;
}

// max value of Node in BST

Node *maxvaluebst(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = minvaluebst(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the elements of the BST (enter -1 to stop): " << endl;
    takeinput(root);
    // traversal of BST
    cout << "Printing the BST:" << endl;
    levelorder(root);

    cout << "Inorder BST" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder BST" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder BST " << endl;
    postorder(root);
    cout << endl;

    // search in bst
    // cout << "Enter the node to find in BST: ";
    // int x;
    // cin >> x;
    // if (searchnumber(root, x)) {
    //     cout << "Node " << x << " found in BST." << endl;
    // } else {
    //     cout << "Node " << x << " not found in BST." << endl;
    // }

    cout << "max :" << maxvaluebst(root)->data << endl
         << "min : " << minvaluebst(root)->data << endl;

    // delete a node
    cout << "Enter the node to delete from BST: ";
    int del;
    cin >> del;
    root = deleteNode(root, del);
    cout << "Printing the BST after deletion:" << endl;
    levelorder(root);

    return 0;
}