
#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data=0, Node* left=NULL, Node*right=NULL)
        :data(data), left(left), right(right) {}
};

Node* transform_r( Node* cur , Node* &root) {
    if ( cur == NULL ) {
        return NULL;
    }

    Node *new_parent;

    if ( cur->right == NULL ) {
        // New root found
        root = cur;
    }
    else {
        new_parent = transform_r( cur->right, root );
        new_parent->right = cur->left;
        new_parent->left = cur;
    }

    cur->left = cur->right = NULL;
    return cur;
}

void transform_i( Node* cur, Node* &root ) {
    stack<Node*> s;
    
    while ( cur != NULL ) {
        s.push( cur );
        cur = cur->right;
    }

    root = s.top();
    s.pop();
    
    Node *tmp;
    cur = root;
    while ( !s.empty() ) {
        tmp = s.top();
        s.pop();
        cur->right = tmp->left;
        cur->left = tmp;
        cur = tmp;
    }

    tmp->left = tmp->right = NULL;
}

void print_tree( Node* cur ) {
    if ( cur == NULL )
        return;

    cout << cur->data << ": ";
    if ( cur->left != NULL )
        print_tree( cur->left );
    if ( cur->right != NULL ); 
        print_tree( cur->right );
}

int main() {
    Node *tmp1, *tmp2, *tmp3, *root;

    // Recursive
    tmp1 = new Node(8);
    tmp2 = new Node(9);

    tmp3 = new Node(7, tmp1, tmp2);
    tmp2 = new Node(6);

    tmp1 = new Node(5, tmp2, tmp3);
    tmp2 = new Node(4);
    
    tmp3 = new Node(3, tmp2, tmp1);
    tmp2 = new Node(2);

    tmp1 = new Node(1, tmp2, tmp3);

    cout << "Transformed recursively: ";
    cout << "\nBefor: ";
    print_tree(tmp1);

    cout << "\nAfter: ";
    transform_r(tmp1, root);
    print_tree(root);
    cout << "\n";

    // Iterative
    tmp1 = new Node(8);
    tmp2 = new Node(9);

    tmp3 = new Node(7, tmp1, tmp2);
    tmp2 = new Node(6);

    tmp1 = new Node(5, tmp2, tmp3);
    tmp2 = new Node(4);
    
    tmp3 = new Node(3, tmp2, tmp1);
    tmp2 = new Node(2);

    tmp1 = new Node(1, tmp2, tmp3);

    cout << "Transformed iteratively: ";
    cout << "\nBefore: ";
    print_tree(tmp1);
    cout << "\nAfter: ";
    transform_i(tmp1, root);
    print_tree(root);
    cout << "\n";

    return 0;
}



