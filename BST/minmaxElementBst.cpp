#include <iostream>
using namespace std;
#define COUNT 10
class Node{
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

int findMin(Node* root){

    if(root==NULL)
    {
        cout << "Error empty tree" << endl;
        return -1;
    }
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;

}
int findMax(Node* root){

    if(root==NULL)
    {
        cout << "Error empty tree" << endl;
        return -1;
    }
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root->data;

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

int main(){

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
    cout << endl;
    printBst(root,0);

    int min = findMin(root);
    cout << "min is : " << min << endl;

    int max = findMax(root);
    cout << "max is : " << max << endl;
}