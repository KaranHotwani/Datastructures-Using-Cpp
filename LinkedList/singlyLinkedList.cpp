#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};
Node* head;
void InsertStart(Node* &temp)
{
    cout << "temp insert " << temp << endl;
    // if(head==NULL){
    //     head = temp;
    //     return;
    // }
    cout << "Inithead" << head << endl;
    temp->next = head;
    head = temp;
    cout << "newhead" << head << endl;
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
    int choice;
    do{
        cout << "\nMenu\n";
        cout << "1.Insert\n";
        cout << "2.Print\n";
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
                cout << temp << endl;
                InsertStart(temp);
                // cout << "data \n"<< temp->data << "next \n"<< temp->next << endl;

                break;
            }
            case 2:
                printLinkedList();
            break;
        }
    } while(choice!=0);
    

    return 0;
}