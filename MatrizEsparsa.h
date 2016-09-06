#ifndef MATRIZESPARSA
#define MATRIZESPARSA

class MatrizEsparsa
{
    private:
        int nLinhas;
        int nColunas;
        int valorComum;

        Linha* linhas;

    public:
        MatrizEsparsa(int l, int c, int v) const;
        virtual ~MatrizEsparsa();
        void incluir(int i) throw():
        void excluir(int i) throw();

};

#endif

