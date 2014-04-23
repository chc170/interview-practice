
#include <iostream>

using namespace std;

int find_min( int array[], int size ) {
    int left = 0, right = size-1;
    int mid = (left + right) / 2;

    while( left < right ) {
        cout << "(" << left << ", " << right << ")\n";
        if ( mid == left )
            return right;

        if ( array[left] < array[right] )
            return left;
        else {
            if ( array[mid] <= array[right] ) {
                right = mid;
                mid = (left + right) / 2;
            }
            else if ( array[mid] > array[right] ) {
                left = mid;
                mid = (left + right) / 2;
            }
        }
    }
    return left;
}

int main() {

    int array[] = { 4,5,6,7,1,2,3 };
    int min = find_min( array, 7 );
    std::cout << "Minimum: array[" << min << "]=" << array[min] << "\n";
    return 0;
}
