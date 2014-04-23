
//4 5 1 2 3, 6
// 123456  0, 7, 5
   se
   m
// 234561  0, 7, 3, 1
// 612345  0, 7, 4, 1
 
bool isInList(int targetValue, int list[], int size) {

    return check( 0, size-1, list, targetValue );
}

bool check( int start, int end, const int *list, int targetValue ) {
    
    // Boundary
    if ( start > end )
        return false;
       
    // Get middle index
    int mid  = (start + end) / 2;
    
    // Target found.
    if ( targetValue == list[mid] )
        return true;
        
    // The right side is in order
    if ( list[mid] < list[end] ) {
        // Target is in the left
        if ( targetValue < list[mid] || targetValue > list[end]) {
            return check(start, mid-1, list, targetValue);
        }
        // Target is in the right side
        else {
            return check(mid+1, end, list, targetValue);
        }
    }
    // The left side is in order
    else {
        // Target is in the right
        if ( targetValue > list[mid] || targetValue < list[start] ) {
            return check(mid+1, end, list, targetValue);
        }
        // Target is in the left side
        else {
            return check(start, mid-1, list, targetValue);
        }    
    }
}

void shuffleArray(int array[], int size)
{
    int r, tmp;
    srand(time(0));
    
    // Swap each item in the array
    for ( int i = 0; i < size-1; i++ ) {
        // Get a random number from 0 to size-i
        r = rand() % (size-i);
        
        // Swap
        tmp = array[size-1-i];
        array[size-1-i] = array[r];
        array[r] = tmp;
    }
}