/* This class will be given a list of words (such as might be tokenized
 * from a paragraph of text), and will provide a method that takes two
 * words and returns the shortest distance (in words) between those two
 * words in the provided text. For example, in this paragraph if your
 * first string was "words" and your second string was "the", your program
 * should return 2. If you were given "given" and the word "were", you
 * should return 1.
 */
#include<vector>
#include<string>
#include<CMath>
using namespace std;
class WordDistanceFinder {
    vector<string> words;
    hash_map< pair<wordOne, wordTwo>, distance >;
    hash_map< word, List<int> > word_hash;
public:
    WordDistanceFinder (vector<string> words) {
        // implementation here
        words = words;
        
        for ( int i = 0; i < words.size(); i++ ) {
            if(word_hash.exist( words[i] ) 
                word_hash[words[i]].push_back(i);
            else {
                word_hash.add ( make_pair( words[i], new vector<int>() ) );
                word_hash[words[i]].push_back(i);
            }
        }
    }
    
    int distance (string wordOne, string wordTwo) {
        // implementation here
        if ( wordOne == wordTwo ) 
            return 0;
            
        int pOne = -1, pTwo = -1;
        int min_dist = MAX_INT, dist;
        
        for ( int i = 0; i < words.size(); i++ ) {
            // Get latest pointers for two words
            if ( words[i] == wordOne ) 
                pOne = i;
            if ( words[i] == wordTwo )
                pTwo = i;
            
            // Check the distance of the two pointers
            if ( pOne != -1 && pTwo != -1 ) {
                dist = Math.abs(pOne - pTwo);
                
                // Update the minimum distance
                if ( dist < min_dist )
                    min_dist = dist;
            }
        }
        
        return min_dist;
    }
}

/**
 * Sample input:
 *
 *          1
 *         / \
 *        3   5
 *       / \   \
 *      2   4   7
 *     /     \
 *    9       8
 *
 * Expected output:
 *    1
 *    3 5
 *    2 4 7
 *    9 8
 *    ==========
 */

#include <queue>
class TreePrinter {
public:
 class Node {
    int value;
    Node left;
    Node right;
    
    Node(int value, Node left, Node right) {
      this.value = value;
      this.left = left;
      this.right = right;
    }
  }
 
 void printTree(Node* root) {
    // implementation here
    queue<Node*> myqueue;
    myqueue.push( root );
    myqueue.push(NULL_PTR);
    
    while( !myqueue.isEmpty() ) {
        // Check the head of the queue
        Node* cur = myqueue.peek();
        // Reach a new level
        if ( cur == NULL_PTR ) {
            cout << "\n";
            if (myqueue.size() == 1)
                return;
            myqueue.push(NULL_PTR);
        }
        else {
            cout << cur->value << " ";
            
            // push children to the queue
            if ( cur->left != NULL )
                myqueue.push(cur->left);
            if ( cur->right != NULL )
                myqueue.push(cur->right);
        }
    
        // pop
        myqueue.pop();
    }
  }
}



