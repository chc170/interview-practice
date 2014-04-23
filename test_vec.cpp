
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> foo (3, 0);
    vector<int> bar;

    bar = foo;

    bar.push_back(10);

    cout << "Foo: " << foo.size() << '\n';
    cout << "Bar: " << bar.size() << '\n';

    return 0;
}

