
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime( int n ) {
	if ( n < 2 )
		return false;

	int square_root = sqrt( n );
	if ( n % 2 == 0 )
		return false;

	for ( int i = 3; i <= square_root; i+=2 ) {
		if ( n % i == 0 )
			return false;
	}

	return true;
}

int main() {

	if (is_prime(929))
		cout << "is prime\n";
	else
		cout << "not prime\n";

	if (is_prime(927))
		cout << "is prime\n";
	else
		cout << "not prime\n";

	return 0;
}