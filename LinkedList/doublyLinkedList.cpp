#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node*  next;
        Node* prev;
};
Node* head;
void insertEnd(Node* &temp)
{
    if(head==NULL)
    {
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->prev = temp1;
}

void insertPosition(Node* &temp,int pos)
{
    //If temp is the first node then it will be head node
    if(head==NULL)
    {
        head = temp;
        return;
    }
    //store address of head in temp1 for traversing the linkedlist
    Node* temp1 = head;
    //handling the case of adding the new node at start
    if(pos==1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    //traversing and getting to one position before of actual position we have to add on
    for(int i=0;i<pos-2;i++)
    {
        temp1=temp1->next;
    }
    //handling the case of adding the new node at end
    if(temp1->next==NULL)
    {
        temp1->next=temp;
        temp->prev=temp1;
        return;
    }
    //handling the case of adding node anywhere in middle.All four links are getting reset
    temp->next = temp1->next;
    temp1->next->prev =  temp;
    temp1->next = temp;
    temp->prev =  temp1;
}
void deletePosition(int pos)
{
    Node* temp = head;
    Node* temp1;
    if(pos==1)
    {
        head = head->next;
        head ->prev = NULL;
        delete temp;
        return;
    }
    for(int i=0;i<pos-2;i++)
    {
        temp = temp->next;
    }
    if(temp->next->next==NULL)
    {
        temp1 = temp->next;
        temp1->prev = NULL;
        temp->next = NULL;
        delete temp1;
        return;
    }
    temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    temp1->next=NULL;
    temp1->prev = NULL;
    delete temp1;
} 
void printLinkedList(){
    Node* temp1 = head;
    while(temp1->next!=NULL)
    {
        cout << temp1->data << "--";
        temp1 = temp1->next;
    }
    cout << temp1->data;
}

int main()
{
    head = NULL;
    int choice;
    do
    {
        cout << "\nMenu Doubly LinkedList\n";
        cout << "1.Insert\n";
        cout << "2.Print\n";
        cout << "3.Insert at position\n";
        cout << "4.Delete Node\n";
        // cout << "5.Reverse\n";
        cout << "0.Quit\n";
        cin >> choice;
        switch(choice)
        {
            case 0:
            {
                exit;
            }
            break;
            case 1:
            {
                Node * temp = new Node();
                cout << "Insert Data\n";
                cin >> temp->data;
                temp->next = NULL;
                temp->prev = NULL;
                insertEnd(temp);
                cout << head->data;
            }
            break;
            case 2:
            {
                printLinkedList();
            }
            break;
            case 3:Node n;
                Node* temp = n;
            {
                Node * temp = new Node();
                cout << "Insert Data\n";
                cin >> temp->data;
                temp->next = NULL;
                temp->prev = NULL;
                cout << "Insert Position\n";
                int pos;
                cin >> pos;
                insertPosition(temp,pos);
            }
            break;
            case 4:
            {
                cout << "Insert Position\n";
                int pos;
                cin >> pos;
                deletePosition(pos);
            }
            break;
        }
    }
    while(choice!=0);
    return 0;
}