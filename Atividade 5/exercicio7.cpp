#include <iostream>

using namespace std;

void inverterSinais(int *a, int *b) {
    *a = -*a;
    *b = -*b;
}

int main() {
    int a = 10;
    int b = -20;

    cout << "Antes:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    inverterSinais(&a, &b);

    cout << "\nDepois:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
