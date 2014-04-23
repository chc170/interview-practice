/*******************************
 *http://www.bearcave.com/random_hacks/permute.html
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string loadData(string &input) {
    cin >> input;
    return input;
}

void swap(string &data, int i, int j) {
    char c = data[i];
    data[i] = data[j];
    data[j] = c;
}

void permute( string &data, const int start ) {
    if ( start >= data.size() ) {
        cout << data << endl;
    }
    else {
        for ( int i = start; i < data.size(); i++ ) {
            swap( data, start, i );     // pick another to be start
            permute( data, start+1 );   // go to next item
            swap( data, start, i );     // swap back
        }
    }
}

int main() {
    string data;

    loadData(data);
    cout << "The results: \n";
    permute(data, 0);

    return 0;
}

