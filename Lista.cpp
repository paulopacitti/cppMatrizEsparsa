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
    No* atual = this->primeiro;
    No* aux;
    for(int i=0; i< tamanho; i++)
    {
        aux = atual->getProx();
        atual->~No();
        atual = aux;
    }
}

void Lista::incluir(No* n) throw()
{

    No* atual;
    if(this->existe(n))
    {
        atual = pesquisar(n);
        atual->setValor(n->getValor());
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

void Lista::excluir(No* n) throw()
{

    if(primeiro->compareTo(n) == 0)
    {
        if(primeiro->getProx() == NULL)
        {
            //this->~Lista();
            return;
        }

        /* Copy the data of next node to head */
        this->primeiro = this->primeiro->getProx();

        // store address of next node
        n = this->primeiro->getProx();

        // Remove the link of next node
        this->primeiro->setProx(this->primeiro->getProx()->getProx());
        // free memory
        n->~No();

        return;
    }


    // When not first node, follow the normal deletion process

    // find the previous node
    No* aux = this->primeiro;
    while(aux->getProx() != NULL && aux->getProx() != n)
        aux = aux->getProx();

    // Check if node really exists in Linked List
    if(aux->getProx() == NULL)
    {
        throw "Elemento não existe na matriz";
        return;
    }

    // Remove node from Linked List
    aux->setProx(aux->getProx()->getProx());

    // Free memory
    n->~No();

    return;
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





