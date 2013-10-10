/***
 * 
 * Slice the input string by comma
 *
 */

#ifndef STRSLICE_HPP
#define STRSLICE_HPP

#include <string>

using namespace std;

class StrSlice{
private:
    static string *_str;
   
public:
    static void setStr(string str) {
        *StrSlice::_str = str;
    }
    
    static string getNext() {
        unsigned pos = _str->find(",");
        string next = _str->substr(0, pos);
        *_str = _str->substr(pos+1);
        
        return next;
    }
};

string *StrSlice::_str = new string();

#endif // STRSLICE_HPP
