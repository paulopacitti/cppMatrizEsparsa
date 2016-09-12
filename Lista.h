#ifndef LISTA
#define LISTA
#include "No.h"
class Lista
{
    private:
        int tamanho;
        No* primeiro;

    public:
        Lista();
        Lista(No* p);
        virtual ~Lista();
        void incluir(No* n) throw();
        void excluir(No* n) throw();
        int getTamanho();

        bool existe(No* n);
        No* pesquisar(No* n);
        No* getByIndex(int i) throw();
        No* getByChave(int c);

};
#endif // ELEMENTO
