#ifndef NO
#define NO
class No
{
    private:
        int chave;
        int valor;
        No* prox;
    public:
        No(int c, int v);
        virtual ~No();

        int getChave() const;
        void setChave(int c);
        int getValor() const;
        void setValor(int v);
        No* getProx();
        void setProx(No* p);

        int compareTo(No* n);

};
#endif // NO
