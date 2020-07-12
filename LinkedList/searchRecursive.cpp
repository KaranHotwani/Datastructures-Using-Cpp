#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* insertStart(Node* head,int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp; 
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

bool searchRecursive(Node* head, int data)
{
    if(head==NULL) return false;
    if(head->data==data)
    {
        return true;
    }
    else
    {
        return searchRecursive(head->next,data);
    }
}

int main(){

    Node* head = NULL;
    head = insertStart(head,10);
    head = insertStart(head,15);
    head = insertStart(head,20);
    head = insertStart(head,25);

    if(searchRecursive(head,22))
    {
        cout <<  "Found" << endl;
    }
    else cout << "Not Found" << endl;
    // cout << searchRecursive(head,22) << endl;

    return 0;
}