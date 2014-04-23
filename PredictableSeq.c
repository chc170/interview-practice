#include <stdio.h>

int main() {
    char input[64];
    scanf( "%s", input );
    
    printf( "%c", input[63] );
    
    return 0;
}
