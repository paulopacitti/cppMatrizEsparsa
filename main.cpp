#include <iostream>
#include "MatrizEsparsa.h"

using namespace std;

int main()
{
    int l, c, v;

    cout << "Digite o número de linhas: \n";
    cin >> l;
    cout << "Digite o número de colunas: \n";
    cin >> c;
    cout << "Digite o valor comum: \n";
    cin >> v;

    MatrizEsparsa m(l, c, v);
    cout << "--------------------- \n ";
    cout << m;



}
