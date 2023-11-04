#include <iostream>

using namespace std;

class Stack
{
private:
    static const int MAX_SIZE = 256;

protected:
    int data[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    ~Stack()
    {
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MAX_SIZE - 1);
    }

    void push(int element)
    {
        if (isFull())
        {
            cout << "Ngan xep da day " << element << endl;
            return;
        }
        top++;
        data[top] = element;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Ngan xep rong" << endl;
            return -1;
        }
        int element = data[top];
        top--;
        return element;
    }

    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    return 0;
}
