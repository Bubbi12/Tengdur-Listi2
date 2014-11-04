#include <iostream>

using namespace std;

/*
Write a void function that takes a linked list
of integers and reverses the order of its nodes.
The function will have one call-by-reference
parameter that is a pointer to the head of
the list. After the function is called,
this pointer will point to the head of a
linked list that has the same nodes as the
original list, but in the reverse of the
order they had in the original list. Note
that your function will neither create nor
destroy an nodes. It will simply rearrange
nodes.
Place your function in a suitable test program.
*/

struct Node
{
    Node* link;
    int data;
};

void ReverseList(Node* &TheHead);


int main()
{
    Node* Head = NULL;
    Node* tmp;
    int n;

    cout << "Enter number of Nodes" << endl;
    cin >> n;

    // Making a Node linking list


    for(int i = 0; i < n; i++) // Creating a list
    {
        tmp = new Node;
        tmp->data = i;
        tmp->link = Head;
        Head = tmp;
    }

    // Going through the link list

    while(tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << endl;

    ReverseList(Head); // Reversing the list

    tmp = Head; // Put tmp front of the list

    while(tmp != NULL) // Go through the list again when the list has been Reverse
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    tmp = Head; // make tmp pointed to the front of the list
    while(Head != NULL) // Deleting the memory from head
    {
        Head = Head->link; // Move head forward in the list
        delete tmp;       // then delete the Node
        tmp = Head;      // Why dont we just delete the head?
    }
    // And why not deleting the Head here ?

}



void ReverseList(Node* &TheHead)
{
    Node* NewHead = NULL; // Make new Head to reverse the list
    Node* tmp; //

    while(TheHead != NULL) // until we have reach the end of the old list
    {
        tmp = TheHead; // Make tmp point to the first node
        TheHead = TheHead->link; // Move head forward
        tmp->link = NewHead; // make tmp Node point to the new list Head
        NewHead = tmp; // and move head front of the new list
    }
    TheHead = NewHead; // make the Old head front of the reverse list
}

