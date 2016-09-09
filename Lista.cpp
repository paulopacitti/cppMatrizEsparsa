#include "Lista.h"
#include "No.h"

Lista::Lista()
{
    this->tamanho = 0;
}

Lista::Lista(No* p)
{
    this->primeiro = p;
    tamanho = 1;
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

void Lista::incluir(No* n)
{
    bool achou = false;
    int chave = 0;
    No* aux = this->primeiro;
    No* aux2;

    if(this->getByIndex(0)->compareTo(n) == -1)
    {
        aux = this->primeiro;
        this->primeiro = n;
        this->primeiro->setProx(aux);
        tamanho++;
        return;
    }
    else
    {
        if(this->getByIndex(tamanho-1)->compareTo(n) == -1)
        {
            this->getByIndex(tamanho-1)->setProx(n);
            tamanho++;
            return;
        }
        else
        {
            while(!achou)
            {
                if(aux->compareTo(n) == -1)
                    achou = true;
                else
                {
                    chave = aux->getChave();
                    aux = aux->getProx();
                }
            }

            aux2 = aux->getProx();
            aux->setProx(n);
            aux->getProx()->setProx(aux2);
        }
    }
}

void Lista::excluir(No* n)
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
}

bool Lista::existe(No* n)
{
    for(int i=0; i < tamanho; i++)
    {
        if(this->getByIndex(i)->compareTo(n) == 0)
            return true;
    }

    return false;
}

No* Lista::getByIndex(int i) throw()
{
    No* aux;
    aux = this->primeiro;

    if((i+1) > tamanho)
        throw "Index não existe na lista";
    else
    {
         for(int j=0; j < i; i++)
            aux = aux->getProx();
         return aux;
    }
}

No* Lista::getByChave(int c) throw()
{
    for(int i=0; i < tamanho; i++)
    {
        if(this->getByIndex(i)->getChave() == c)
            return this->getByIndex(i);
    }
    throw "Chave não existe";

}





