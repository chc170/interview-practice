#include <iostream>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Node{
public:
    int d;
    Node *left;
    Node *right;

    Node(int d=0, Node *left=NULL, Node *right=NULL):
        d(d), left(left), right(right) {}
};

Node* _decode(stringstream& ss) {
    string s_data, s_count;
    int data, count;

    // Grab data
    if ( !ss.eof() ) getline(ss, s_data, ' ');
    else return NULL;

    if ( !ss.eof() ) getline(ss, s_count, ' ' );
    else return NULL;

    data = atoi(s_data.c_str());
    count = atoi(s_count.c_str());

    // Assign data
    Node *left = NULL, 
         *right = NULL;

    if ( (count & 1) == 1 ) left = _decode(ss);
    if ( (count & 2) == 2 ) right = _decode(ss);

    return new Node(data, left, right);
}

Node* btree_decode(const string& code) {
    stringstream ss(code);
    return _decode(ss);
}

void btree_encode(const Node* const cur, stringstream &code) {

    if ( cur == NULL )
        return;

    int count = 0;
    code << cur->d << " ";
    if ( cur->left != NULL ) 
        count += 1;
    if ( cur->right != NULL )
        count += 2;
    code << count << " ";

    btree_encode(cur->left, code);
    btree_encode(cur->right, code);
}

///////////////////////////////////////////

void levelbylevel( Node *root ) {
    Node *cur;
    queue<Node*> q;

    q.push(root);
    q.push(new Node(-1)); // dummy

    while( q.size() ) {
        cur = q.front();
        if (q.size() > 1) {
            if ( cur->d == -1 ){
                q.push(new Node(-1));
                cout << "\n";
            }
            else {
                cout << cur->d << " ";
                if ( cur->left != NULL )
                    q.push(cur->left);
                if ( cur->right != NULL )
                    q.push(cur->right);
            }
        }
        q.pop();
    }

    cout << "\n\n";
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

    levelbylevel(root);

    stringstream ss;
    btree_encode(root, ss);
    cout << ss.str() << "\n";

    Node *newroot;
    newroot = btree_decode(ss.str());

    if ( newroot != NULL )
        levelbylevel(newroot);
 
    return 0;
}

