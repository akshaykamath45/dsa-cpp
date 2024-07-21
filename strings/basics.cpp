#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    // string s1 = "akshay";
    // string s2(5, 'a');
    // cout << s1 << endl;
    // cout << s2 << endl;

    // append
    // string s1 = "fam";
    // string s2 = "ily";
    // // cout << s1.append(s2);
    //  cout << s1+s2;

    // clear
    // string s1 = "hello";
    // cout << s1 << endl;
    // s1.clear();
    // cout << s1 << endl;

    // compare
    // string s1 = "abc";
    // string s2 = "xyz";
    // string s3 = "abc";
    // cout << s1.compare(s2) << endl;
    // cout << s1.compare(s3) << endl;

    // empty
    // string s1 = "hello";
    // s1.clear();
    // if (s1.empty())
    // {
    //     cout << "string is empty";
    // }
    // else
    // {
    //     cout << s1 << endl;
    // }

    // erase(from which index, how many characters)
    // string s1 = "nincompoop";
    // s1.erase(3, 3);
    // cout << s1 << endl;

    // find("word") - returns the first index where the complete word occurs
    // string s1 = "nincompoop";
    // int ind = s1.find("comp");
    // cout << ind << endl;

    // insert(at which index,word to be inserted)
    // string s1="akshay";
    // s1.insert(3,"hi");
    // cout<<s1;

    // substr(from which index, how many characters)
    // string s1 = "akshay kamath";
    // cout << s1.substr(0, 6) << endl;

    // converting string to integer
    // string s1 = "786";
    // int x = stoi(s1);
    // cout << x << endl;
    // x += 2;
    // cout << x << endl;
    // return 0;

    // converting integer to string
    // int x = 786;
    // string str1 = to_string(x);
    // cout << str1 + "2" << endl;

    // sort lexicographically
    string s1 = "akshay kamath";
    sort(s1.begin(), s1.end());
    cout << s1 << endl;
}