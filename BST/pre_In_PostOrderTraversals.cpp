#include<iostream>
#include<queue>
using namespace std;
#define COUNT 10
class Node {
    public:
        int data;
        Node* left;
        Node* right;
};

Node* createNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node* insert(Node* root,int data){

    if(root==NULL)
    {
        root = createNode(data);
    }
    else if(data<=root->data)
    {
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}


void printBst(Node* root,int space){

      if (root == NULL)  
        return;  
  
    space += COUNT;  
  
    printBst(root->right, space);  
    
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    printBst(root->left, space);  
}

int preOrder(Node* root)//root left right
{
    if(root==NULL)
    {
        return -1;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return 1;
}

int InOrder(Node* root)// left root right
{
    if(root==NULL)
    {
        return -1;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
    return 1;
}

int postOrder(Node* root)//left right root
{
    if(root==NULL)
    {
        return -1;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    return 1;
}


int main()
{
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,38);
    root = insert(root,15);
    root = insert(root,13);
    root = insert(root,9);
    root = insert(root,23);
    root = insert(root,2);
    root = insert(root,10);
    root = insert(root,11);
    root = insert(root,40);
    cout << endl;

    printBst(root,0);

    cout << "Pre-order :";
    preOrder(root);
    cout << endl;
    cout << "In-order :";
    InOrder(root);
    cout << endl;
    cout << "Post-order :";
    postOrder(root);
    cout << endl;
    return 0;
}