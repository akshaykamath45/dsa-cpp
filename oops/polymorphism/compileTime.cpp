#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// constructor overloading
class Student
{
public:
    string name;
    Student()
    {
        cout << "non-parameterised" << endl;
    }
    Student(string name)
    {
        this->name = name;
        cout << "parameterised" << endl;
    }
};

// function overloading
class Print
{
public:
    void show(int x)
    {
        cout << "int : " << x << endl;
    }
    void show(char x)
    {
        cout << "char : " << x << endl;
    }
};
int main()
{
    Student s1;
    Student s2("akshay");
    Print p1;
    p1.show(1);
    p1.show('&');

    return 0;
}