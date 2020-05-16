#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};
Node* top;
void printStack(){
    Node* temp1 = top;
    while(temp1!=NULL)
    {
        cout << temp1->data << "\n";
        temp1 = temp1->next;
    }
}
void pushStack(Node* &temp)
{
    temp->next = top;
    top = temp;
    printStack();
}
void popStack()
{
    Node* temp = top;
    top=top->next;
    temp->next = NULL;
    temp->data = 0;
    delete temp;
    printStack();
}

void peek()
{
    cout << " Top element is: " << top->data << endl;
}


int main()
{
    top = NULL;
    int choice;
    do
    {
        cout << "Menu Stack Using Linked list\n";
        cout << "1.Push\n";
        cout << "2.Pop\n";
        cout << "3.Peek\n";
        cout << "4.Print\n";
        cout << "0.Quit\n";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 0:
            {
                exit;
            }
            break;
            case 1:
            {
                cout << "Enter Data\n";
                Node* temp = new Node();
                cin >> temp->data;
                temp->next = NULL;
                cout << endl;
                pushStack(temp);
            }
            break;
            case 2:
            {
                popStack();
            }
            break;
            case 3:
            {
                peek();
            }
            break;
            case 4:
            {
                printStack();
            }
            break;
        }
    }
    while(choice!=0);
    return 0;
}