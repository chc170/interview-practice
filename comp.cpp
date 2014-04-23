

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <utility>

class Comparator{
private:
    const std::map<std::string, int> m;

public:
    Comparator( const std::map<std::string, int>& _m ): m(_m) {}

    bool operator() ( const std::string& a, const std::string& b ) const {
        return m.find(a)->second < m.find(b)->second;
    }
};



int main() {
    std::map<std::string, int> m;
    m.insert(std::make_pair("a", 7));
    m.insert(std::make_pair("b", 6));
    m.insert(std::make_pair("c", 4));
    m.insert(std::make_pair("d", 5));
    m.insert(std::make_pair("e", 3));
    m.insert(std::make_pair("f", 2));
    m.insert(std::make_pair("g", 1));
    
    // One extra pair of parentheses to prevent Most Vexing Parse problem
    std::priority_queue<std::string, std::vector<std::string>, Comparator> pq( (Comparator(m)) ); 

    pq.push("b");
    pq.push("d");
    pq.push("a");
    pq.push("c");
    pq.push("g");
    pq.push("f");
    pq.push("e");

    std::string a;
    while( pq.size() ) {
        a = pq.top();
        std::cout << (a) << "\n";
        pq.pop();
    }

    std::cout << "\n";
    
    std::priority_queue<std::string> spq;

    spq.push("b");
    spq.push("d");
    spq.push("a");
    spq.push("c");
    spq.push("g");
    spq.push("f");
    spq.push("e");

    while( spq.size() ) {
        std::cout << spq.top() << "\n";
        spq.pop();
    }

    std::cout << "\n";

    return 0;
}



