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

void levelOrder(Node* root)
{
    if(root==NULL) return;
    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        if(current->left!=NULL)q.push(current->left);
        if(current->right!=NULL)q.push(current->right);
        cout << current->data << "  ";
        q.pop();
    }
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
    cout << endl;

    printBst(root,0);
    levelOrder(root);
    cout << endl;
    return 0;
}