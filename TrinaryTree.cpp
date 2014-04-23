/////////////////////////////////////////////////
// Topic: Trinary tree insertion and deletion
// Language: C++
// Author: Chih-Chuan Chan
// Date: 11/8/2013

#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *mid;
    Node *right;

    Node(int data=0, Node *left=NULL, Node *mid=NULL, Node *right=NULL)
        :data(data), left(left), mid(mid), right(right) {}
};

class TrinaryTree{
public:
    TrinaryTree():root(NULL) {};
    void InsertNode(Node *newnode);
    void DeleteNode(int data);
    void PrintTree();

private:
    Node *root;
    void _insert(Node *cur, Node *newnode);
    void _delete(Node **pptr, Node *cur, int data);
    void _print(Node *cur, string prefix);
};

void TrinaryTree::InsertNode(Node *newnode) {
    // Insert the first node
    if ( this->root == NULL )
        root = newnode;

    // Insert the rest of nodes
    else
        _insert(this->root, newnode);
}

void TrinaryTree::_insert(Node *cur, Node *newnode) {
    // Insert to the middle
    if ( cur->data == newnode->data ) {
        if ( cur->mid != NULL )
            _insert(cur->mid, newnode);
        else
            cur->mid = newnode;
    }
    // Insert to the left
    else if ( cur->data > newnode->data ) {
        if ( cur->left != NULL )
            _insert(cur->left, newnode);
        else
            cur->left = newnode;
    }
    // Insert to the right
    else if ( cur->data < newnode->data ) {
        if ( cur->right != NULL )
            _insert(cur->right, newnode);
        else
            cur->right = newnode;
    }
}

void TrinaryTree::DeleteNode(int data) {
    _delete(&(this->root), this->root, data);
}

void TrinaryTree::_delete(Node **pptr, Node *cur, int data) {
    // Node not found.
    if ( cur == NULL )
        return; 

    // Node found.
    if ( cur->data == data ) {
        // Delete from middle
        if( cur->mid != NULL )
            _delete(&(cur->mid), cur->mid, data);

        // Need a new parent
        else {
            if ( cur->left != NULL ) {
                // Merge left and right
                if ( cur->right != NULL ) {
                    _insert(cur->left, cur->right);
                    (*pptr) = cur->left;
                }
                // Only left child exists
                else
                    (*pptr) = cur->left;
            }
            // Only right child exists
            else
                (*pptr) = cur->right;
        }
    }

    // Node at right side or left side.
    else {
        if ( cur->data > data )
            _delete( &(cur->left), cur->left, data );
        else
            _delete( &(cur->right), cur->right, data );
    }            
            
}

void TrinaryTree::PrintTree() {
    cout << "=Tree starts========================\n";
    _print(this->root, "");
}

void TrinaryTree::_print(Node *cur, string prefix) {
    // Use pre-order traversal

    // Current node
    cout << prefix << cur->data << endl;
    
    // Visit left
    if (cur->left != NULL) {
        cout << prefix << "Left: \n";
        _print(cur->left, prefix + "  ");
    }

    // Visit middle
    if (cur->mid != NULL) {
        cout << prefix << "Middle: \n";
        _print(cur->mid, prefix + "  ");
    }

    // Visit right
    if (cur->right != NULL) {
        cout << prefix << "Right: \n";
        _print(cur->right, prefix + "  ");
    }
}

int main() {
    // Construct tree
    TrinaryTree tt;
    tt.InsertNode(new Node(5));
    tt.InsertNode(new Node(4));
    tt.InsertNode(new Node(9));
    tt.InsertNode(new Node(5));
    tt.InsertNode(new Node(7));
    tt.InsertNode(new Node(2));
    tt.InsertNode(new Node(2));
    tt.InsertNode(new Node(8));
    tt.PrintTree();

    // Delete leaf
    tt.DeleteNode(7);
    tt.PrintTree();

    // Delete middle
    tt.DeleteNode(5);
    tt.PrintTree();
    
    // Delete root
    tt.DeleteNode(5);
    tt.PrintTree();

    // Delete between
    tt.DeleteNode(9);
    tt.PrintTree();

    // Delete nobody
    tt.DeleteNode(10);
    tt.PrintTree();

    return 0;
}

