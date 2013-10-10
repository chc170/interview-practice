/**
 *
 * Generate client list 
 * Field: Email, phone number, initial
 * N : number of clients on the list
 *
 */


#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

static const int N = 1000000;

string getEmail() {
    string email, sc;
    int ci;
    
    for (int i = 0; i < 3; i++) {
        ci = rand() % 36;
        ci = (ci < 10)? (ci += 48) : (ci += 87);
          
        sc = (char) ci;
        email += sc;
    }
    return email;
}

string getPhone() {
    string phone, sc;
    int ci;
    
    for (int i = 0; i < 4; i++) {
        ci = rand() % 10 + 48;
          
        sc = (char) ci;
        phone += sc;
    }
    return phone;
}

string getInitial() {
    string initial, sc;
    int ci;
    
    for (int i = 0; i < 2; i++) {
        ci = rand() % 26 + 65;
          
        sc = (char) ci;
        initial += sc;
    }
    return initial;
}

int main (int argc, char* argv[]) {
    string email, phone, initial;
    ofstream output;
    output.open("clients.dat");    
    
    // Random seed
    srand (time(0));
    
    // Randomly generate each client
    for (int i = 0; i < N; i++) {
        // email
        email = getEmail();
        
        // phone
        phone = getPhone();
        
        // initial
        initial = getInitial();
        
        // output
        output << email << "," << phone << "," << initial << "\n";
    }
    
    output.close();
    return 0;
}
