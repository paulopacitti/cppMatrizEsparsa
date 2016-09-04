#include "No.h"

No:No(int c, int v)
{
    this->chave = c;
    this->valor = v;
    this->prox = NULL;
}

No:~No()
{
    this->prox = NULL;
    delete this->prox;
}

int No::getChave()
{
    return this->chave;
}

int No::setChave(int c)
{
    this->chave = c;
}

int No::getValor()
{
    return this->valor;
}

void No::setValor(int v)
{
    this->valor = v;
}

No* No::getProx()
{
    return this->prox;
}

void No::setProx(No* p)
{
    this->prox = p;
}

int No::compareTo(No* n)
{
    if(this->getChave() > n->getChave())
        return 1;
    if(this->getChave() < n->getChave())
        return -1;
    else
        return 0;
}

