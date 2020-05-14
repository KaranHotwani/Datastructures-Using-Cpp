#include<iostream>
using namespace std;
#define size 100


int stack[size],top=-1;

void pushStack(int data)
{
    if(top>=size-1)
    {
        cout << "Stack overflow\n";
        return;
    }
    top++;
    stack[top] = data;
    return;
}
void popStack()
{
    if(top==-1)
    {
        cout << "Stack Underflow\n";
        return;
    }
    stack[top]=0;
    top--;
}

void peek()
{
    if(top==-1)
    {
        cout << "Stack Underflow\n";
        return;
    }
    if(top>=size-1)
    {
        cout << "Stack overflow\n";
        return;
    }
    cout << "Top element is: " << stack[top] << endl;
}
void printStack()
{
    if(top>-1)
    {
        for(int i=top;i>=0;i--)
        {
            cout << stack[i] << endl;
        }
    }
}
int main()
{
    // cout << sizeof(stack)/sizeof(int);
    int choice;
    // cout << top;
    do
    {
        cout << "Menu Stack\n";
        cout << "1.Push\n";
        cout << "2.Pop\n";
        cout << "3.Peek\n";
        cout << "4.Print\n";
        // cout << "4.Delete Node\n";
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
                pushStack(data);
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