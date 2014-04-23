///////////////////////////////////////////////
// Topic: Convert from string to long 
// Language: C++
// Author: Chih-Chuan Chan
// Date: 11/8/2013

#include <iostream>
#include <string>

// Define exception code
const int INVALID_INPUT = 10;
const int OVERFLOW = 20;

using namespace std;

long stringToLong(string s) 
{ 
    /* to convert a string to a long */ 
    long result = 0, temp = 0;
    bool neg = false;
    int index = 0;

    // Check sign
    if ( s[index] == '-' ) {
        neg = true;
        index++;
    }

    // Parse digit by digit
    for ( ; index < s.size(); ++index ) {
        // Check invalid value.
        if ( s[index] > '9' || s[index] < '0' ) 
            throw INVALID_INPUT; 
        
        // Convert charater to integer.
        // Add to result.
        temp += (s[index] - '0');
        
        // Check overflow
        if ( temp < result )
            throw OVERFLOW;
        result = temp;

        // Calculate correct base.
        temp = result * 10;
    }

    // Use correct sign
    return (neg)? -result : result;
} 
 
void test(string input, long answer) 
{ 
    long i;
    try {
        i = stringToLong(input); 
    }
    catch (int e){
        if ( e == INVALID_INPUT ) {
            cerr << "Input: " << input << " Result: Invalid input test succeed.\n";
            return;
        }
        if ( e == OVERFLOW ) {
            cerr << "Input: " << input << " Result: Overflow test succeed.\n";
            return;
        }
    }
    
    cout << "Input: " << input << "  Answer: " << answer;
    cout << " Result: ";

    if (i == answer) 
        // success 
        cout << i << " Success.\n";
    else 
        // failure 
        cout << i << " Failed.\n";
} 

int main() {
    // Run tests.
    test("123", 123);
    test("-123", -123);
     
    test("123.123", 0);
    test("adfa", 0);
    test("9999999999999999999999999999999999999999999999", 0);

    return 0;
}

