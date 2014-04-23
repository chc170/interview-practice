#include <iostream>
using namespace std;

int *p = NULL;

int func() {
    return *p;
}

//int c = func();

int d = *p;

int main() {
    int a = 5;
    cout << a;
    return 0;
}
