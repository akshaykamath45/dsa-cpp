#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// static variable inside a function
void fun()
{
    static int x = 0;
    cout << "x : " << x << endl;
    x++;
}

// static variable inside a class
class A
{
public:
    static int x;

    void incrementX()
    {
        cout << "x : " << x << endl;
        x = x + 1;
    }
};
int A::x = 0;

// static objects
class ABC
{
public:
    ABC()
    {
        cout << "constructor" << endl;
    }

    ~ABC()
    {
        cout << "destructor" << endl;
    }
};
int main()
{
    // fun();
    // fun();
    // fun();

    // A obj1;
    // A obj2;

    // obj1.incrementX();
    // obj2.incrementX();

    if (true)
    {
        static ABC obj;
    }
    cout << "end of main function" << endl;

    return 0;
}