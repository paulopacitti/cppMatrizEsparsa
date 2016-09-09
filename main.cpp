#include <iostream>
#include "MatrizEsparsa.h"

using namespace std;

int main()
{
    int l, c, v;

    cout << "Digite o n�mero de linhas: \n";
    cin >> l;
    cout << "Digite o n�mero de colunas: \n";
    cin >> c;
    cout << "Digite o valor comum: \n";
    cin >> v;

    MatrizEsparsa m(l, c, v);
    m.incluir(2,2,4);
    m.incluir(3,2,5);
    m.incluir(1,1,6);
    cout << "--------------------- \n ";
    cout << m;



}
