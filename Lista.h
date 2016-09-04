#ifndef LISTA
#define LISTA
#include "No.h"
class Lista
{
    private:
        int tamanho;
        No* primeiro;

    public:
        Lista(No* p);
        virtual ~Lista();
        void incluir(No* n);
        void excluir(No* n);
        int getTamanho();

        bool existe(No* n);
        No* operator[](int i) throw();

};
#endif // ELEMENTO
