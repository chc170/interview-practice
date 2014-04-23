
#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data=0, Node *next=NULL)
        :data(data), next(next){}
};

bool checkPalindrone( Node *tail, Node *&front, Node *head, int& count ) {

    // Run tail pointer to the end of list
    if(tail->next != NULL) {
        count++;
        if(!checkPalindrone( tail->next, front, head, count ))
            return false;
    }
    // Tail touch the end. Front starts going from the head.
    else {
        front = head;
    }
  
    // Prevent double comparing
    if (count < 1)
        return true;

    // Compare the two nodes 
    if(front->data != tail->data)
        return false;
    else {
        // Shrink the count and move to next node
        count -= 2;
        front = front->next;
        return true;
    }
}

int main() {
    Node *root, *newnode1, *newnode2, *front;
    int count = 0;

    newnode1 = new Node(1);
    newnode2 = new Node(2, newnode1);
    newnode1 = new Node(3, newnode2);
    newnode2 = new Node(2, newnode1);
    newnode1 = new Node(1, newnode2);

    root = newnode1;
    if (checkPalindrone(root, front, root, count)) 
        cout << "It's a palindrone.\n";
    else
        cout << "It's not a palindrone.\n";

    return 0;
}

