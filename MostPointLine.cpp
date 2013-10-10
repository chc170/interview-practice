/***
 *
 * Searching for a line on a plane that passes the most number of nodes.
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

static const int BOUNDARY = 100;
typedef pair<double, double> LinePair;

/**
 * A node on a 2D plane
 */
class Node {
private:
    double _x;
    double _y;

public:
    Node (double x, double y) {
        _x = x;
        _y = y;
    }
    
    inline double getX() const {
        return _x;
    }
    
    inline double getY() const {
        return _y;
    }
};

/**
 * A 2D plane
 */
class Plane {
private:
    vector<Node*> _nodes;
    
public:
    Plane (int N) {
        double x, y;
        Node *newnode;
        srand(time(0));
        
        // Randomly create N nodes 
        for (int i = 0; i < N; i++) {
            x = rand() % BOUNDARY;
            y = rand() % BOUNDARY;
            newnode = new Node(x, y);
            _nodes.push_back(newnode);
        }
    }
    
    void printNodes() {
        for (int i = 0; i < _nodes.size(); i++) {
            cout << i << " (" << _nodes[i]->getX() << ", " \
                << _nodes[i]->getY() << ")" << endl;
        }
    }
    
    // Find the line passing th most number of nddes
    LinePair findMostNodeLine() {
        // Generate pairs from every two nodes
        map<LinePair, double> lines;
        double d, b, dx, dy;
        
        for (int i = 0; i < (_nodes.size()-1); i++) {
            for (int j = (i+1); j < _nodes.size(); j++) {
                dx = _nodes[j]->getX() - _nodes[i]->getX();
                dy = _nodes[j]->getY() - _nodes[i]->getY();
                
                // slope and intercept
                d = (dx == 0)? 1 : (dy / dx);
                b = _nodes[j]->getY() - (d * _nodes[j]->getX());
                LinePair newpair (d, b);
                lines[newpair]++;                
            }
        }
        
        // Find the pair with largest value
        map<LinePair, double>::iterator iter;
        double largest_value = 0;
        LinePair largest_pair;
        
        for (iter = lines.begin(); iter != lines.end(); iter++) {
            if (iter->second > largest_value) {
                largest_value = iter->second;
                largest_pair = iter->first;
            }
        }
        
        return largest_pair;
    }
};

/**
 * Main function
 */
int main() {
    LinePair result;
    
    Plane *plane = new Plane(1000);
    
    result = plane->findMostNodeLine();
    cout << result.first << ", " << result.second << endl;

    cout << "Press enter to exit...";
    getchar();
    return 0;
}
