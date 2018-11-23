using namespace std;

class Produto{
    private:
        int codigo;
        string descricao;
        float valor;
        int quantidade;
    public:
        Produto (int codigo, string descricao, float valor);
        Produto (int codigo, string descricao, float valor, int quantidade);
        void setCodigo (int codigo);
        int getCodigo ();
        void setDescricao (string descricao);
        string getDescricao ();
        void setValor (float valor);
        float getValor ();
        void setQuantidade (int quantidade);
        int getQuantidade ();
};