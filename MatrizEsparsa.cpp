#include "MatrizEsparsa.h"
#include "Lista.h"
#include "No.h"
#include <iostream>
#include <ostream>

MatrizEsparsa:: MatrizEsparsa(int l, int c, int v) throw()
{
    this->nLinhas = l;
    this->nColunas = c;
    this->valorComum = v;

    if(l == 0 || c == 0)
        throw "Matriz Inválida";

    this->linhas = new Lista();

}

MatrizEsparsa::~MatrizEsparsa()
{
    this->linhas = NULL;
}

void MatrizEsparsa::incluir(int l, int c, int v) throw()
{
    No* novaColuna = new No(l,c, v);
    if(v != valorComum && validaLinhaColuna(l, c))
        this->linhas->incluir(novaColuna);
    else
    {
        if(this->linhas->existe(novaColuna))
            this->linhas->incluir(novaColuna);
        else
            throw "Elemento já existe ou não compreende as dimensões da matriz";
    }

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
    No* aux;
    for(int i=1; i <= (m.nLinhas); i++)
    {
        o << "\n";
        for(int j = 1; j <= m.nColunas; j++)
        {
            aux = new No(i,j,0);
            if(!m.linhas->existe(aux))
            {
                o << " ";
                o << m.valorComum;
            }
            else
            {
                o << " " ;
                o << (int)(m.linhas->pesquisar(aux)->getValor());
            }
        }
    }
   // return o;
}




