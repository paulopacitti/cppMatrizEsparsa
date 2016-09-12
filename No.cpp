#include "No.h"
#include <cstddef>

No::No(int l, int c, int v)
{
    this->linha = l;
    this->coluna = c;
    this->valor = v;
    this->prox = NULL;
}

No::~No()
{
   this->prox = NULL;
   this->linha = NULL;
    this->coluna = NULL;
    this->valor = NULL;
}

int No::getLinha()
{
    return this->linha;
}

void No::setLinha(int l)
{
    this->linha = l;
}

int No::getColuna()
{
    return this->coluna;
}

void No::setColuna(int l)
{
    this->coluna = l;
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
    if(this->getLinha() > n->getLinha())
        return 1;
    if(this->getLinha() < n->getLinha())
        return -1;
    if(this->getLinha() == n->getLinha() && this->getColuna() == n->getColuna())
        return 0;
    if(this->getLinha() == n->getLinha() && this->getColuna() > n->getColuna())
        return 1;
    else
        return -1;
}

