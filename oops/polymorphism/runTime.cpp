#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Parent
{
public:
    void getInfo()
    {
        cout << "parent class" << endl;
    }
    virtual void hello()
    {
        cout << "hello from parent" << endl;
    }
};
class Child : public Parent
{
public:
    void getInfo()
    {
        cout << "child class" << endl;
    }
    void hello()
    {
        cout << "hello from child" << endl;
    }
};
int main()
{
    Parent p1;
    p1.getInfo();
    p1.hello();
    Child c1;
    c1.getInfo();
    c1.hello();

    return 0;
}