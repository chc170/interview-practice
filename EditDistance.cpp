
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int minDistance( string w1, string w2 ) {
    vector< vector<int> > dist( w1.size() + 1, vector<int>( w2.size() + 1, 0 ) );

    vector< vector<int> >::iterator it_w1;
    vector<int>::iterator it_w2;
    int min;

    // Initialize the 1st row and column
    for ( int i = 0; i < w1.size() + 1; ++i ) 
        dist[i][0] = i;

    for ( int j = 0; j < w2.size() + 1; ++j ) 
        dist[0][j] = j;

    // Start DP
    for ( int i = 1; i < w1.size() + 1; ++i ) {
        for ( int j = 1; j < w2.size() + 1; ++j ) {
            if ( w1[i-1] == w2[j-1] ) {
                // Two characters are matched.
                dist[i][j] = dist[i-1][j-1];
            }
            else {
                int rep = dist[i-1][j-1] + 1; // replace w1[i-1] to match w2[j-1]
                int add = dist[i][j-1] + 1;   // add w2[j-1] to the end of w1
                int del = dist[i-1][j] + 1;   // delete w1[i-1] from w1

                // Find the minimum choice.
                min = fmin(rep, add);
                min = fmin(del, min);
                dist[i][j] = min;
            }
        }
    }

    return dist[w1.size()][w2.size()];
}

int main() {
    int result = 0;

    result = minDistance("abcdefg", "abdefg");
    
    cout << result << endl;

    return 0;
}

