#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;
};

class Student : public Person
{
public:
    string rollno;
};
class Teacher : public Person
{
public:
    string subject;
    double salary;
};

int main()
{
    Student s1;
    Teacher t1;
    s1.name = "akshay";
    s1.rollno = "116";
    cout << s1.name << endl;
    cout << s1.rollno << endl;

    t1.name = "rohit";
    t1.subject = "dl";
    cout << t1.name << endl;
    cout << t1.subject << endl;

    return 0;
}