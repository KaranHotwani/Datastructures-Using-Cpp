#include<iostream>
using namespace std;
#define size 100

int queueArray[size],front = -1,rear = -1;

bool isEmpty(){
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else return false;
}

bool isFull(){
    if(rear== size-1)
    {
        return true;
    }
    else return false;
}
void enqueue(int data)
{
    if(isEmpty())
    {
        front = rear = 0;
    }
    else if(isFull())
    {
        cout << "Queue is full. Can't add new elements\n";
    }
    else
    {
        rear++;
    }
    queueArray[rear] = data;
}

int dequeue()
{
    int data;
    if(isEmpty())
    {
        cout << "Queue is Empty. Cannot remove elements\n";
    }
    else if(front==rear)
    {
        data = queueArray[front];
        front = rear = -1;
    }
    else
    {
        data = queueArray[front];
        front++;
    }
    return data;
}
void printFront()
{
    if(!isEmpty()) cout << "Front element is :" << queueArray[front] << endl;
    else cout << "-1" << endl;
}

void printQueue()
{
    if(!isEmpty())
    {
        for(int i=front;i<=rear;i++)
        {
            cout << queueArray[i] << " | ";
        }
    }
    cout << endl;
}
int main()
{
    int choice;
    do
    {
        cout << "Menu Queue Using Array\n";
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
                int data;
                cin >> data;
                enqueue(data);
                cout << "added element " << data << endl; 
            }
            break;
            case 2:
            {
                int data = dequeue();
                cout << "removed element " << data << endl;
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