#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    ~Student()
    {
        cout << "Destructor called-> deallocating memory after creating object " << endl;
        delete cgpaPtr; // could lead to memory leak, if we don't deallocate variables created using dynamic memory
    }

    void getInfo()
    {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaPtr << endl;
    }
};
int main()
{
    Student s1("rahul kumar", 8.9);
    s1.getInfo(); // 8.9
    return 0;
}