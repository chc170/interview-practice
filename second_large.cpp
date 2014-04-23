#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int d;
    Node *left;
    Node *right;

    Node(int d=0, Node *left=NULL, Node *right=NULL):
        d(d),left(left), right(right) {}
};

Node* largest( Node *cur ) {
    if (cur == NULL)
        return NULL;

    if (cur->right != NULL)
        return largest(cur->right);
    else
        return cur;
}

Node* second_largest( Node *cur, Node *parent ) {
    if (cur == NULL)
        return NULL;

    if (cur->right != NULL)
        return second_largest(cur->right, cur);

    // The largest one has left child
    if (cur->left != NULL)
        return largest(cur->left);

    // The largest one has no child
    return parent;
}

void add_node(Node *newnode, Node *cur) {
    if ( cur->d > newnode->d ) {
        if ( cur->left == NULL )
            cur->left = newnode;
        else
            add_node(newnode, cur->left);
    }
    else {
        if ( cur->right == NULL )
            cur->right = newnode;
        else 
            add_node(newnode, cur->right);
    }
}

int main() {
    // Construct the tree
    Node *root, *newnode;
    root = new Node(4);
    add_node(new Node(1), root);
    add_node(new Node(2), root);
    add_node(new Node(8), root);
    add_node(new Node(7), root);
    add_node(new Node(10), root);
    add_node(new Node(9), root);

    Node *sec_largest = second_largest(root, NULL);
    cout << sec_largest->d << "\n";
    return 0;
}
