#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[1000];
    }
    void push(int x)
    {
        if (top == size)
        {
            cout << "Stack overflow, excceding size";
            return;
        }
        top = top + 1;
        arr[top] = x;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack empty, cannot pop";
            return 0;
        }
        int x = arr[top];
        return x;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "Stack empty, no top element";
            return;
        }
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Stack s;
    for (int i = 0; i <= 4; i++)
    {
        s.push(i);
    }
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    int top = s.Top();
    int size = s.Size();
    cout << "Top " << top << endl;
    cout << "Size " << size << endl;
    s.printStack();
    return 0;
}