/**
 * Tree to list.
 * Turn a binary tree to doubly linked list
 **/

#include <iostream>

using namespace std;

class BiNode {
public:
    BiNode(int data, BiNode* left=NULL, BiNode* right=NULL)
        :data(data), left(left), right(right) {}

    int data;
    BiNode* left;
    BiNode* right;
};

// Tree to list iteratively
// - In order traversal
void TreeToList(BiNode* cur, BiNode* &pre, BiNode* &head) {
    // Left
    if ( cur->left != NULL )
        TreeToList(cur->left, pre, head);

    // Self
    if ( pre == NULL ) 
        head = cur;
    else 
        pre->right = cur;

    cur->left = pre;
    pre = cur;

    // Right
    if ( cur->right != NULL )
        TreeToList(cur->right, pre, head);

}

// Tree to list recursively
// - Do left, do right, combine

int main() {
    BiNode* newnode1 = new BiNode(0);
    BiNode* newnode2 = new BiNode(1, newnode1);
    BiNode* newnode3 = new BiNode(3);
    newnode1 = new BiNode(2, newnode2, newnode3);

    newnode2 = new BiNode(6);
    newnode3 = new BiNode(5, NULL, newnode2);
    newnode2 = new BiNode(4, newnode1, newnode3);

    BiNode* head, *cur, *pre = NULL;
    TreeToList(newnode2, pre, head);
    cur = head;
    while( cur->right != NULL ) {
        cout << cur->data << " ";
        cur = cur->right;
    }
    cout << cur->data << "\n";

    while( cur->left != NULL ) {
        cout << cur->data << " ";
        cur = cur->left;
    }
    cout << cur->data << "\n";

    return 0;
}

