#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *traverseArray(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next; // mover=temp;
    }
    return head;
}
int main()
{
    int arr[4] = {1, 3, 5, 8};
    // 2 ways

    // 1st way, creating the object and pointer separately, access using .
    // Node x = Node(arr[0], nullptr);
    // Node *y = &x;
    // cout << "Pointer y storing the memory location of x " << y << endl;
    // cout << "x.data " << x.data << endl;
    // cout << "x.next " << x.next << endl;

    // 2nd way, (preffered) creating the object and pointer together using new keyword, access using ->
    // Node *y = new Node(arr[3]);
    // cout << "Pointer y storing the memory location of current node " << y << endl;
    // cout << "x.data " << y->data << endl;
    // cout << "x.next " << y->next << endl;
    Node *ans = traverseArray(arr, 4);
    Node *current = ans;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}