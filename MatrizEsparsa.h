#ifndef MATRIZESPARSA
#define MATRIZESPARSA
#include <stdio.h>
#include "Lista.h"
#include <ostream>


class MatrizEsparsa
{
    private:
        int nLinhas;
        int nColunas;
        int valorComum;
        Lista** vetLinhas;

        bool validaLinhaColuna(int l, int v);

    public:
        MatrizEsparsa(int l, int c, int v) throw();
        virtual ~MatrizEsparsa();
        void incluir(int l, int c, int v) throw();
        void excluir(int l, int c, int v) throw();
        friend std::ostream& operator<< (std::ostream& o, MatrizEsparsa m);

};
extern std::ostream& operator<< (std::ostream& o, MatrizEsparsa m);


#endif

