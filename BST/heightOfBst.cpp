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

int findHeight(Node* root){

    if(root==NULL)
    {
        return -1;
    }
    return max(findHeight(root->left),findHeight(root->right))+1;
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
    
    int height = findHeight(root);
    cout << "Height is : " << height << endl;
}