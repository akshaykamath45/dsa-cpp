#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age)
    {
        cout << "parent constructor " << endl;
        this->name = name;
        this->age = age;
    }
};

class Student : public Person
{
public:
    int rollno;
    Student(string name, int age, int rollno) : Person(name, age)
    {
        cout << "child constructor" << endl;
        this->rollno = rollno;
    }
    void getInfo()
    {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};
int main()
{
    Student s1("akshay", 20, 116);
    s1.getInfo();
    return 0;
}