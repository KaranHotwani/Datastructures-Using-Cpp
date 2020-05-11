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
        // cout << "3.Print Node Count\n";
        // cout << "4.Delete Node\n";
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
        }
    }
    while(choice!=0);
    return 0;
}