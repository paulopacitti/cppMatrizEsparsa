#include "MatrizEsparsa.h"

MatrizEsparsa:: MatrizEsparsa(int l, int c, int v)
{
    this->nLinhas = l;
    this->nColunas = c;
    this->valorComum = v;

    this->vetLinhas = new Lista*[l-1];

    for(int i=0; i<(l-1); i++)
    {
        this->vetLinhas[i] = NULL;
    }
}

MatrizEsparsa::~MatrizEsparsa()
{

}

void MatrizEsparsa::incluir(int l, int c, int v) throw()
{
    if(v != valorComum && validaLinhaColuna())
    {
        No novaColuna = new No(c, v);
        if(!vetLinhas[l].existe(novaColuna))
        {
            if(vetLinhas[l-1] == NULL)
            {
                Lista novaLinha = new Lista(novaColuna);
                novaLinha.incluir(novaColuna);
                vetLinhas[l-1] = novaLinha;
            }
            else
                vetLinhas[l-1].incluir(novaColuna);
        }
    }
    else
        throw "Elemento já existe ou não compreende as dimensões da matriz";
}

void MatrizEsparsa::excluir(int l, int c, int v) throw()
{
    if(v != valorComum && validaLinhaColuna())
    {
        No novaColuna = new No(c, v);
        if(vetLinhas[l-1].existe(novaColuna))
            vetLinhas[l-1].excluir(novaColuna);
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

OStream& operator<< (OStream& o, MatrizEsparsa m)
{
    for(int i=0; i < m.nLinhas -1; i++)
    {
        for(int j = 0; j < m.nColunas -1; i++)
        {
            if(m.vetLinhas)
        }
    }
}




