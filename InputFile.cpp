#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


void getw(string& t, ifstream& in) {
    in >> t;
}

int read_string(vector<string> &words, ifstream& in) {
    int i = 0;
    while( !in.eof() )
        getw(words[i++], in);
    retur (i-1);
}

int main() {
    ifstream in("text");
    vector<string> w(1000);
    
    int howmany = read_string(w, in);
    w.resize(howmany);

    sort(w.begin(), w.end());

    for (auto str:w)
        cout << str << "\t";
    
    return 0;
}

