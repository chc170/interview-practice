
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node{
public:
    Node(int d=0, Node *left=NULL, Node *right=NULL): data(d), left(left), right(right){}

    int data;
    Node *left;
    Node *right;
};

void levelbylevel( Node *root ) {
    Node *cur;
    queue<Node*> q;

    q.push(root);
    q.push(new Node(-1)); // dummy

    while( q.size() ) {
        cur = q.front();
        if (q.size() > 1) {
            if ( cur->data == -1 ){
                q.push(new Node(-1));
                cout << "\n";
            }
            else {
                cout << cur->data << " ";
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

int main() {
    // Construct the tree
    Node *newnode1, *newnode2, *newnode3, *newnode4;

    newnode1 = new Node(4, NULL, NULL);
    newnode2 = new Node(5, NULL, NULL);
    newnode3 = new Node(2, newnode1, newnode2);

    newnode1 = new Node(6, NULL, NULL);
    newnode2 = new Node(7, NULL, NULL);
    newnode4 = new Node(3, newnode1, newnode2);

    newnode1 = new Node(1, newnode3, newnode4);

    cout << "Level by level:\n";
    levelbylevel( newnode1 );

    return 0;
}

