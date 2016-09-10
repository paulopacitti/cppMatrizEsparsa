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
    /* Special case for the head end */
    if (this->tamanho == 0 || this->primeiro->compareTo(n) == 1)
    {
        n->setProx(this->primeiro);
        this->primeiro = n;
    }
    else
    {
        /* Locate the node before the point of insertion */
        atual = this->primeiro;
        while(atual->getProx() != NULL && atual->getProx()->compareTo(n) == -1)
        {
            atual = atual->getProx();
        }

        n->setProx(atual->getProx());
        atual->setProx(n);
    }
}

void Lista::excluir(No* n) throw()
{
    No* aux;
    if(this->existe(n))
    {
        for(int i=0; i < tamanho; i++)
        {
            if(this->getByIndex(i)->compareTo(n) == 0)
            {
                aux = this->getByIndex(i)->getProx();
                this->getByIndex(i)->~No();
                this->getByIndex(i-1)->setProx(aux);
            }
        }
    }
    else
        throw "Nó não existe na lista";
}

bool Lista::existe(No* n)
{
    if(this->tamanho != 0)
    {
         for(int i=0; i < this->tamanho; i++)
        {
            if(this->getByIndex(i)->compareTo(n) == 0)
                return true;
        }
    }
    return false;
}


No* Lista::getByIndex(int i) throw()
{
    No* aux;
    aux = this->primeiro;

    if((i) > tamanho)
        throw "Index não existe na lista";
    else
    {
        if(i == 0)
            return this->primeiro;
        else
        {
            for(int j=0; j < i; i++)
                aux = aux->getProx();
            return aux;
        }
    }

}

No* Lista::getByChave(int c)
{
    for(int i=0; i < (tamanho); i++)
    {
        if(this->getByIndex(i)->getChave() == c)
            return this->getByIndex(i);
    }
    No* retorno = new No(-1,-1);
    return retorno;
}





