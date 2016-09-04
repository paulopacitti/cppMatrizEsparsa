#include "Lista.h"
#include "No.h"

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
    chave = 0;
    No* aux = this->primeiro;
    No* aux2;

    if(this[0]->compareTo(n) == -1)
    {
        aux = this->primeiro;
        this->primeiro = n;
        this->primeiro->setProx(aux);
        tamanho++;
        return;
    }
    else
    {
        if(this[tamanho-1]->compareTo(n) == -1)
        {
            this[tamanho -1]->setProx(n);
            tamanho++;
            return;
        }
        else
        {
            while(!achou)
            {
                if(aux->compareTo(n) == -1)
                    achouIndex = true;
                else
                {
                    chave = aux->getChave();
                    aux = aux->getProx();
                }
            }

            aux2 = aux->getProx();
            aux->setProx(n);
            aux->getProx()->setProx();
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
            if(this[i]->compareTo(n) == 0)
            {
                aux = this[i]->getProx();
                ~this[i]();
                this[i-1]->setProx(aux);
            }
        }
    }
}

bool Lista::existe(No* n)
{
    for(int i=0; i < tamanho; i++)
    {
        if(this[i]->compareTo(n) == 0)
            return true;
    }

    return false;
}

No* Lista::operator[](int i)
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


