
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    string data;
    Node(): left(NULL), right(NULL), data("") {}
    Node(Node *_left, Node *_right, string _data):
        left(_left), right(_right), data(_data) {}
};

void inOrderTraverse(Node *cur, vector<string>& order) {
    if (cur->left != NULL)
        inOrderTraverse(cur->left, order);
    order.push_back(cur->data);
    if (cur->right != NULL)
        inOrderTraverse(cur->right, order);
}

int main() {
    Node *root;
    Node *newnode1, *newnode2, *tmproot;
    
    // Construct binary tree
    newnode1 = new Node(NULL, NULL, "1");
    newnode2 = new Node(NULL, NULL, "3");
    tmproot = new Node(newnode1, newnode2, "2");
    newnode1 = tmproot;
    newnode2 = new Node(NULL, NULL, "11");
    tmproot = new Node(newnode2, NULL, "12");
    newnode2 = new Node(NULL, tmproot, "9");
    tmproot = new Node(newnode1, newnode2, "4");
    root = tmproot;
    
    // Do traversal
    vector<string> order;
    inOrderTraverse(root, order);

    for ( int i = 0; i < order.size(); i++ ) {
        cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}
