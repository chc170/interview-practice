#include <iostream>

using namespace std;

int main() {

    int a = 15;

    a ^= -1;
    a += 1;

    cout << a << "\n";

    a = 31;
    int b = ~a;
    cout << b << "\n";

    return 0;
}

