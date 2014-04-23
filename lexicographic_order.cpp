

#include <iostream>

using namespace std;


void Print(int N) {
    int count = 0;
    int b = 1; // base
    int c = 1; // current number

    while(count < N) {
        if( c <= N ) { 
            cout << c << "(" << count << ")" << endl;
            count++;

            // Find next with current 
            // number as a prefix 
            c *= 10;
        }
        else {
            // Can't be prefix
            c /= 10;
            // Find next            
            while(++c % 10 == 0)
                ((--c) /= 10);
        }
    }
}

int cc = 0;
void Lex(int N, int c) {
    // c: current number
    if(c > N) return;

    while( c <= N ) {
        cout << c << "(" << cc++ << ")" << endl;

        // Check next number with the same prefix
        c *= 10;
        Lex(N, c);
        c /= 10;

        // Check next number changed least digit
        c++;

        // The checks of a certain digit is done.
        if( c % 10 == 0 )
            return;
    }
}


int main() {
    Print(1000);
    //Lex(1000, 1);
    return 0;
}

