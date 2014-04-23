/** 
 * Find the number of possible combination with 3 numbers
 * that could be 3 edges of a triagle.
 * Complexity: O(N^2)
 **/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findNumberOfTriangles ( vector<int>& arr ) {
    int n = arr.size(), count = 0;

    // Sort the array
    sort( arr.begin(), arr.end() );

    // Set the smallest element: i       // N
    for ( int i = 0; i < n - 2; ++i ) {
        // Set the largest number to the next number 
        // of the second number: k
        int k = i+2;

        // Set the second number: j      // N
        for ( int j = i+1; j < n - 1; ++j ) {
            // Increase k to find the largest possible number
            // **Trick
            //   We don't need to lower down k when we change j,
            //   because the second number increases, the 
            //   largest possible number must larger than 
            //   the largest number with previous second number.
            while ( k < n && arr[k] < arr[i] + arr[j] ) 
                k++;

            // Use the index to count how many possible number in the range
            count += (k-j-1);
        }
    }
    return count;
}

void printArr ( vector<int>& arr ) {
    cout << " array: ";
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); ++it ) {
        cout << (*it) << ", ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(0));

    // Create an array
    vector<int> arr;
    //arr.push_back(10);
    //arr.push_back(101);
    //arr.push_back(22);
    //arr.push_back(200);
    //arr.push_back(21);
    //arr.push_back(300);
    //arr.push_back(100);

    for (int i = 0; i < 50; ++i ) 
        arr.push_back(rand() % 80 + 1);
    printArr(arr);

    int result = findNumberOfTriangles(arr);
    printArr(arr);
    
    cout << "Count: " << result << endl;
    return 0;
}
