#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(Node* &temp)
{
    if(front==NULL && rear==NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    Node* temp;
    if(front == NULL)
    {
        cout << "No elements to remove\n";
    }
    else if(front == rear)
    {
        temp = front;
        front = NULL; 
        rear = NULL;
        delete temp;
    }
    else
    {
        temp = front;
        front =  front->next;
        delete temp;
    }
}

void printQueue(){
    if(rear!=NULL)
    {
        Node* temp1 = front;
        while(temp1->next!=NULL)
        {
            cout << temp1->data << "-->";
            temp1 = temp1->next;
        }
        cout << temp1->data << endl;
    }
    
}

void printFront(){
    if(front!=NULL) cout << "Front element is :" << front->data << endl;
    else cout << " No elements in queue\n";
}
int main()
{
    int choice;
    do
    {
        cout << "Menu Queue Using Linked list\n";
        cout << "1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.Front\n";
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
                enqueue(temp);
            }
            break;
            case 2:
            {
                dequeue();
            }
            break;
            case 3:
            {
                printFront();
            }
            break;
            case 4:
            {
                printQueue();
            }
            break;
        }
    }
    while(choice!=0);
    return 0;
}