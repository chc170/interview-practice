/*******************************
 * http://www.daniweb.com/software-development/cpp/code/274075/all-permutations-non-recursive
 * (c) Sven Forstmann
 */
#include <iostream>

int main() {
    char c;
     
    std::string dd = "123";

    int total=1, size=dd.size(), index;
    for (int i=1; i<=size; total*=i++);
    // Generate each result
    for (int i=0; i<total; i++)
    {
        std::string avail=dd;
        // Generate each item in a result
        for (int j=size, div=total; j>0; j--) 
        {
            div /= j;
            index = (i/div)%j;

            printf("(%d, %d) div: %d,  idx: %d  = ", i, j, div, index);
            printf("%c", avail[index] );
            
            // Remove the picked item
            avail.erase(index, 1) ;
            printf("\n");
        }
        printf("\n");
        std::cin >> c;
    }
    printf("permutations:%d\n",total);
    
    std::cin >> c;
    return 0;
}
