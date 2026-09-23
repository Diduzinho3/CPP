#include <iostream>

using namespace std;

int main() {
    int N;

    cout << "Quantidade de elementos: ";
    cin >> N;

    int *vetor = new int[N];

    for(int i = 0; i < N; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> vetor[i];
    }

    int maior = vetor[0];

    for(int i = 1; i < N; i++) {
        if(vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    cout << "Maior valor: " << maior << endl;

    delete[] vetor;

    return 0;
}
