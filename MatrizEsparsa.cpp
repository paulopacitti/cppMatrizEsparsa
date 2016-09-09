#include "MatrizEsparsa.h"
#include "Lista.h"
#include "No.h"
#include <iostream>
#include <ostream>

MatrizEsparsa:: MatrizEsparsa(int l, int c, int v)
{
    this->nLinhas = l;
    this->nColunas = c;
    this->valorComum = v;

    this->vetLinhas = new Lista*[l];

    for(int i=0; i<4; i++)
    {
        this->vetLinhas[i] = NULL;
    }
}

MatrizEsparsa::~MatrizEsparsa()
{

}

void MatrizEsparsa::incluir(int l, int c, int v) throw()
{
    if(v != valorComum && validaLinhaColuna(l, c))
    {
        No* novaColuna = new No(c, v);
        if(vetLinhas[l-1] == NULL)
        {
            Lista* novaLinha = new Lista(novaColuna);
            novaLinha->incluir(novaColuna);
            vetLinhas[l-1] = novaLinha;
        }
        else
        {
            if(this->vetLinhas[l-1]->existe(novaColuna) == false)
                vetLinhas[l-1]->incluir(novaColuna);
        }

    }
    else
        throw "Elemento já existe ou não compreende as dimensões da matriz";
}

void MatrizEsparsa::excluir(int l, int c, int v) throw()
{
    if(v != valorComum && validaLinhaColuna(l, c))
    {
        No* novaColuna = new No(c, v);
        if(vetLinhas[l-1]->existe(novaColuna))
            vetLinhas[l-1]->excluir(novaColuna);
    }
    else
        throw "Elemento não existe na matriz";

}

bool MatrizEsparsa::validaLinhaColuna(int l, int c)
{
    if(l <= this->nLinhas && c <= this->nColunas)
        return true;
    else
        return false;
}

std::ostream& operator<< (std::ostream& o, MatrizEsparsa m)
{
    for(int i=0; i < (m.nLinhas); i++)
    {
        o << "\n";
        for(int j = 0; j < m.nColunas; j++)
        {
            if(m.vetLinhas[i] == NULL || m.vetLinhas[i]->getByChave(j)->getChave() == -1)
            {
                o << " ";
                o << m.valorComum;
            }
            else
                o << " " + m.vetLinhas[i]->getByIndex(j)->getValor();
        }
    }
    return o;
}




