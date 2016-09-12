#include "Lista.h"
#include "No.h"
#include <cstddef>

Lista::Lista()
{
    this->tamanho = 0;
}

Lista::Lista(No* p)
{
    this->primeiro = p;
    this->tamanho = 1;
}

Lista::~Lista()
{
    this->primeiro = NULL;
    this->tamanho = 0;
}

void Lista::incluir(No* n) throw()
{

    No* atual;
    if(this->existe(n))
    {
        if(n->getValor() == 0)
            this->excluir(n);
        else
        {
            atual = pesquisar(n);
            atual->setValor(n->getValor());
        }

        return;
    }
    if (this->tamanho == 0 || this->primeiro->compareTo(n) == 1)
    {
        if (this->tamanho == 0)
        {
            this->primeiro = n;
            this->tamanho++;
            return;
        }
        else
        {
            n->setProx(this->primeiro);
            this->primeiro = n;
            this->tamanho++;
            return;
        }
    }
    else
    {
        atual = this->primeiro;
        while(atual->getProx() != NULL && atual->getProx()->compareTo(n) == -1)
        {
            atual = atual->getProx();
        }

        n->setProx(atual->getProx());
        atual->setProx(n);
        this->tamanho++;
    }
}

bool Lista::existe(No* n)
{
    No* aux = this->primeiro;
    if(this->tamanho != 0)
    {
        for(int i=0; i < this->tamanho-1; i++)
        {
            if(aux->compareTo(n) == 0)
                return true;
            else
                aux = aux->getProx();
        }

    }
    return false;
}

void Lista::excluir(No* n)
{
    if(this->primeiro->compareTo(n) == 0)
    {
        if(this->primeiro->getProx() == NULL)
        {
            this->primeiro == NULL;
            return;
        }

        /* Copy the data of next node to head */
        n = this->primeiro;
        this->primeiro = this->primeiro->getProx();
        // free memory
        delete n;
        return;
    }
    No* atual = this->primeiro;
    while(atual->getProx() != NULL && atual->getProx() != n)
        atual = atual->getProx();

    if(atual->getProx() == NULL)
        return;

    // Remove node from Linked List
    atual->setProx(atual->getProx()->getProx());
    delete n;

    return;
}

No* Lista::pesquisar(No* n)
{
    bool achou = false;
    No* aux = this->primeiro;
    if(this->existe(n))
    {
        while(!achou)
        {
            if(aux->compareTo(n) == 0)
                achou = true;
            else
                aux = aux->getProx();
        }
        return aux;
    }
}





