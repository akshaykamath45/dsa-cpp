#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "gntrjkjnhglbdfgrgnjttdddfd";

    // brute force - run two loops, maintain count of max element
    // int maxi = 0;
    // char storeMaxElement = 'a';
    // for (int i = 0; i < s.size(); i++)
    // {
    //     int count = 0;
    //     for (int j = i; j < s.size(); j++)
    //     {
    //         if (s[j] == s[i])
    //         {
    //             count++;
    //         }
    //         if (count > maxi)
    //         {
    //             maxi = count;
    //             storeMaxElement = s[j];
    //         }
    //     }
    // }
    // cout << "max freq element " << storeMaxElement << ", freq " << maxi << endl;

    // better approach - create an array of 26 elements, storing each alphabers count
    int maxi = 0;
    char storeMaxElement = 'a';
    vector<int> freq(25, 0);
    for (int i = 0; i < s.size(); i++)
    {

        freq[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxi)
        {
            maxi = freq[i];
            storeMaxElement = i+'a';
        }
    }

    cout << "max freq element " << storeMaxElement << ", freq " << maxi << endl;
    return 0;
}