#ifndef NO
#define NO
class No
{
    private:
        int linha;
        int coluna;
        int valor;
        No* prox;
    public:
        No(int l, int c, int v);
        virtual ~No();

        int getLinha();
        void setLinha(int l);
        int getColuna() ;
        void setColuna(int c);
        int getValor();
        void setValor(int v);
        No* getProx();
        void setProx(No* p);

        int compareTo(No* n);
        char* toString();

};
#endif // NO
