#include<iostream>
using namespace std;
class Node{
    public:
        static int nodeCount;
        int data;
        Node* next;
};
int Node::nodeCount = 0;
Node* head;
void insertStart(Node* &temp)
{
    temp->next = head;
    head = temp;
    Node:: nodeCount++;
}
void insertEnd(Node* &temp)
{
    Node* temp2 = head;
    if(head==NULL)
    {
        head = temp;
        Node:: nodeCount++;
        return;
    }
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    Node:: nodeCount++;
}

void insertPosition(Node* &temp,int pos)
{
    Node* temp2 = head;
    if(head==NULL)
    {
        head = temp;
        Node:: nodeCount++;
        return;
    }
    if(pos==1)
    {
        temp->next = head;
        head = temp;
        Node:: nodeCount++;
        return;
    }
    for(int i=0;i<pos-2;i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    Node:: nodeCount++;
}
void printLinkedList(){
    Node* temp1 = head;
    while(temp1!=NULL)
    {
        cout << temp1->data << "-->";
        temp1 = temp1->next;
    }
}

int main()
{
    head = NULL;
    cout << head; 
    int choice;
    do{
        cout << "\nMenu\n";
        cout << "1.Insert\n";
        cout << "2.Print\n";
        cout << "3.Print Node Count\n";
        cout << "0.Quit\n";
        cin >> choice;
        switch(choice)
        {
            case 0:
                exit;
                break;
            case 1:
            { 
                Node* temp = new Node();
                cout << "Enter data\n";
                cin >> temp->data;
                temp->next = NULL;
                int ch;
                // cout << temp << endl;
                cout << "1. Insert at start of Linked List \n";
                cout << "2. Insert at end of Linked List \n";
                cout << "3. Insert at a particular position of Linked List \n";
                cin >> ch;
                switch(ch){
                    case 1:
                    {
                        insertStart(temp);
                        break;
                    }
                    case 2:
                    {
                        insertEnd(temp);
                        break;
                    }
                    case 3:
                    {
                        cout << "Insert Position\n";
                        int pos;
                        cin >> pos;
                        insertPosition(temp,pos);
                        break;
                    }
                }
                
                // cout << "data \n"<< temp->data << "next \n"<< temp->next << endl;

                break;
            }
            case 2:
            {
                printLinkedList();
            }
            break;
            case 3:
            {
                cout << "Node Count is  "<< Node:: nodeCount << endl;
            }
        }
    } while(choice!=0);
    

    return 0;
}