#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int size;
    int index;

public:
    Stack()
    {
        this->index = 0;
        this->size = 5;
        this->arr = new int[size];
    }
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->index = -1;
    }
    void push(int num1)
    {
        if (!isFull())
        {
            this->index++;
            this->arr[index] = num1;
            cout << "Data Push Succesfully " << endl;
        }
        else
        {
            cout << "Stack is Full" << endl;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            this->index--;
            cout << "Data Sucessfully Pop out" << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
    bool isEmpty()
    {
        return (this->index == -1);
    }
    bool isFull()
    {
        return (this->index == this->size-1);
    }
    int peek()
    {
        if (this->index == -1)
        return -1;
        else
        return arr[index];
    }
    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty " << endl;
        
        }
        else
        {
        for (int i = 0; i<= index; i++)
        {
            cout << " arr["<<i<<"] : "<<this->arr[i] << endl;
        }
        }
    }
        ~Stack()
        {
            delete arr;
            arr=NULL;
            cout<<"Memory is Free"<<endl;
        }
    
};
enum Menu
{
    PUSH = 1,
    POP,
    PEEK,
    PRINTSTACK,
    EXIT,
    DEFAULT
};
int main()
{
    int size, choice, value, index;
    cout << "Enter Size of the array :" << endl;
    cin >> size;
    Stack str(size);
    while (true)
    {
        cout << "1.PUSH" << endl;
        cout << "2.POP" << endl;
        cout << "3.PEEK" << endl;
        cout << "4.PRINTSTACK" << endl;
        cout << "5.EXIT" << endl;
        cout << "Enter the choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case PUSH:
            cout << "Enter the value " << endl;
            cin >> value;
            str.push(value);
            break;
        case POP:
            str.pop();
            break;
        case PEEK:
            value = str.peek();
            cout<<"Top Value :"<<value<<endl;
            break;
        case PRINTSTACK:
            str.printStack();
            break;
         case EXIT:
         cout<<"Exiting "<<endl;
         return 0;
        case DEFAULT:
            cout << "You Enter invalid choice" << endl;
            break;
        }
    }

    return 0;
}