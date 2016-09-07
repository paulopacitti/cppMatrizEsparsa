#ifndef MATRIZESPARSA
#define MATRIZESPARSA


class MatrizEsparsa
{
    private:
        int nLinhas;
        int nColunas;
        int valorComum;
        Lista[] vetLinhas;

        bool validaLinhaColuna(int l, int v);

    public:
        MatrizEsparsa(int l, int c, int v) const;
        virtual ~MatrizEsparsa();
        void incluir(int l, int c, int v) throw():
        void excluir(int l, int c, int v) throw();
        friend OStream& operator<< (OStream& o, MatrizEsparsa m);

};

extern OStream& operator<< (OStream& o, MatrizEsparsa m);

#endif

