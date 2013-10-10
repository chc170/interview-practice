/***
 * 
 * List all pairs of clients that are considered similar
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "StrSlice.hpp"

using namespace std;


/**
 * Client object
 *  - Store information of each client
 *  - Email, phone number, initial
 */
class Client {
public:
    Client (string email, string phone, string initial) {
        _email = email;
        _phone = phone;
        _initial = initial;
    }
    
    inline string getEmail() const {
        return _email;
    }
    
    inline string getPhone() const {
        return _phone;
    }
    
    inline string getInitial() const {
        return _initial;
    }
    
    string getField(int field) const {
        switch(field) {
        case 1:
            return _email;
            break;
        case 2:
            return _phone;
            break;
        case 3:
            return _initial;
            break;            
        }
    }
    
private:
    string _email;
    string _phone;
    string _initial;
};

/**
 * Client Analyser
 *  - Load client list from file
 *  - Sort by 3 different elements
 *  - Store pairs in hash map
 */
typedef pair<Client*, Client*> ClientPair;
typedef map<ClientPair, int>::const_iterator SimilarIterator;

class ClientAnalyser {
private:
    vector<Client*> _clients;
    map<ClientPair, int> _similar;
    
public:
    bool loadData(string filename);
    void sortBy(bool (*comp)(const Client*, const Client*));
    void analyse(int field);
    
    int getSize() {
        return _clients.size();
    }
    
    void printList() {
        for (int i = 0; i < 10; i++)
            cout << _clients[i]->getEmail() << " : " << 
            _clients[i]->getPhone() << " : " << 
            _clients[i]->getInitial() << endl   ;
    }
    
    void printMap() {
        Client *client1, *client2;
        int count;
        
        for (SimilarIterator iter = _similar.begin(); iter != _similar.end();
            iter++) {
            client1 = iter->first.first;
            client2 = iter->first.second;
            count = iter->second;
            
            if (count > 1) {
                cout << "(" << client1->getEmail() << " : " 
                     << client1->getPhone() << " : "
                     << client1->getInitial() << ") ("
                     << client2->getEmail() << " : " 
                     << client2->getPhone() << " : "
                     << client2->getInitial() << ") ("
                     << count << ")\n";
            }
        }
    }
};

// Comparison function
bool EmailComp (const Client* a, const Client* b) {
    return a->getEmail() < b->getEmail();
}

bool PhoneComp (const Client* a, const Client* b) {
    return a->getPhone() < b->getPhone();
}

bool InitialComp (const Client* a, const Client* b) {
    return a->getInitial() < b->getInitial();
}

// Load data from file
bool ClientAnalyser::loadData(string filename) {
    string line, email, phone, initial;
    ifstream input;
    Client *newclient;
    
    input.open(filename.c_str());
    
    if (!input.is_open())
        return false;
    
    while (input.good()) {
        // Get a line from file
        getline(input, line);
        StrSlice::setStr(line);
        
        // Separate data by comma
        email = StrSlice::getNext();
        phone = StrSlice::getNext();
        initial = StrSlice::getNext();
        
        // Store it in to Client object
        newclient = new Client(email, phone, initial);
        _clients.push_back(newclient);
    }
    input.close();
    
    return true;
}

// Sorting function using STL
void ClientAnalyser::sortBy(bool (*comp)(const Client*, const Client*)) {
    sort(_clients.begin(), _clients.end(), comp);
}

// Analyse clients by current order
//  - Store all pairs within the same group into hash map
void ClientAnalyser::analyse(int field) {
    int j;
    
    for (int i = 0; i < _clients.size() - 1; i++) {
        // Start checking from the next item
        j = i + 1;
        while ( j < _clients.size() &&
            (_clients[i]->getField(field) == _clients[j]->getField(field))) {
                                        
            // Check existence
            ClientPair mypair (_clients[i], _clients[j]);
            // New pair
            if (_similar.find(mypair) == _similar.end()) {
                // Push the pair in the other order
                _similar[(ClientPair (_clients[j], _clients[i]))]++;
            }
            // Existent pair
            else {
                _similar[mypair]++;
            }
            
            // Add to hash map
            j++;
        }
    }
}


/**
 * Main function
 */
int main() {
    ClientAnalyser ca;
    ca.loadData("clients.dat");

    // Check identical email
    ca.sortBy(EmailComp);
    ca.analyse(1);

     // Check identical phone number
    ca.sortBy(PhoneComp);
    ca.analyse(2);

    // Check identical initial
    ca.sortBy(InitialComp);
    ca.analyse(3);

    // Print out the result
    ca.printMap();

  
    char c; cin >> c;
    return 0;   
}
