#ifndef ELEMENTO
#define ELEMENTO
class Elemento
{
    private:
        int chave;
        int valor;
    public:
        Elemento(int c, int v);
        virtual ~Elemento();
        getChave(int c) const;
        setChave(int c);
        getValor(int v) const;
        setValor(int v);


};
#endif // ELEMENTO
