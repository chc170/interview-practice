
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


vector<string>* get_suffix_array( string input ) {
	vector<string> *str_array = new vector<string>();

	for ( int i = 0; i < input.size(); i++ ) {
		str_array->push_back( input.substr(i) );
	}

	return str_array;
}

int lcp( string a, string b ) {
	int len = 0;

	while ( a[len] == b[len] ) {
		len++;
	}

	return len;
}



// Test case: babaaaabcbabaaaaa0


int main() {

	string ori = "babaaaabcbabaaaaa0";

	// 1. Suffix array
	vector<string> * str_array = get_suffix_array(ori);

	// 2. Sort
	sort( str_array->begin(), str_array->end() );

	// 3. Longest common prefix between adjacent suffixes
	string lrs = "";
	int len = 0;

	for ( int i = 0; i < ori.size() - 1; i++ ) {
		len = lcp( str_array->at(i), str_array->at(i+1) );
		if ( len > lrs.size() ) {
			lrs = str_array->at(i).substr(0, len);
		}
	}

	cout << lrs << endl;

/*
	for (int i = 0; i < str_array->size(); i++ ) {
		cout << str_array->at(i) << "\n";
	}
	cout << endl;
*/
	return 0;
}