#include<bits/stdc++.h> 
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

bool checkBst(Node* root)
{
    if(root==NULL) return true;
    checkBst(root->left);
    if(root->left!=NULL && root->left->data>root->data)
    {
        return false;
    }
    if(root->right!=NULL && root->right->data<root->data)
    {
        return false;
    }
    cout << root->data << ' ';
    checkBst(root->right);
    return true;
    
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

    
   bool isBst = checkBst(root);
   cout << endl;
   cout << isBst << endl;
    return 0;
}