#include <iostream>

using namespace std;

int main() {
    int val = 50;
    int *ptr = &val;

    *ptr = 100;

    cout << "Valor de val: " << val << endl;
    cout << "Valor atraves do ponteiro: " << *ptr << endl;

    return 0;
}
