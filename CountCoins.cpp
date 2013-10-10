/**
 * Find minimum number of coins to present N dollars.
 */

#include <iostream>
#include <vector>

using namespace std;
const int MAX = numeric_limits<int>::max();

class CountCoins{
private:
    int *_coins;
    int _length;
    int _GetMinCount(int N);   
        
public:
    CountCoins() {   
        _length = 3;
        _coins = new int[_length];  
        _coins[0] = 1;
        _coins[1] = 7;
        _coins[2] = 9;  
    }
    
    int GetMinCount(int N);   
};
/*
int CountCoins::_GetMinCount(int N){
}*/

int CountCoins::GetMinCount(int N){
    // Negative N is not allowed.
    if (N < 0)
        return MAX;
        
    // Meet the units.
    for (int i = 0; i < _length; i++) {
        if (N == _coins[i])
            return 1;
    }
    
    // Find minimum possible.
    int min = MAX, tmp = 0;
    
    for (int i = 0; i < _length && (N - _coins[i]) > 0; i++) {
        tmp = GetMinCount((N - _coins[i]));
        if (tmp < min) {
            min = tmp;
        }
    }
    
    // Add one more coin to meet value N.
    return (min + 1);
} 


int main () {
    int input;
    CountCoins *cc = new CountCoins();

    while (1) {
        cout << "Enter a number N: ";
        cin >> input;
        if (input < 1)
            break;
        cout << "It needs " << cc->GetMinCount(input) << " coins.\n";
    }
    
    return 0;
}
