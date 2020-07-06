#include<iostream>
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

Node* insertNode( Node* root,int data)
{
    if(root==NULL)
    {
        root = createNode(data);
    }
    else if(data<=root->data)
    {
        root->left = insertNode(root->left,data);
    }
    else 
    {
        root->right = insertNode(root->right,data);
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

bool search(Node* root,int data){

    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data){
        return true;
    }
    else if(data<root->data)
    {
        search(root->left,data);
    }
    else{
        search(root->right,data);
    }
}
int main()
{
    Node* root = NULL;
    int choice;
    do
    {   
        cout << "Menu BST Implementation \n";
        cout << "1.Insert\n";
        cout << "2.Search\n";
        cout << "3.Delete\n";
        cout << "4.Print\n";
        cout << "0.Quit\n";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
            {
                int data;
                cout<< "Enter Data :" << endl;
                cin >> data;
                root = insertNode(root,data);
                cout << root;   
            }
            break;
            case 2:
            {
                int data;
                cout << "Insert Element to be searched \n";
                cin >> data;
                bool result = search(root,data);
                if(result) cout << "Found \n";
                else cout << "Not Found\n";
            }
            break;
            case 3:
            {}
            break;
            case 4:
            {
                printBst(root,0);
            }
            break;
            case 0:
            {
                exit;
            }
            break;
        }
    }
    while(choice!=0);

    return 0;
}