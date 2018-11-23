using namespace std;

class Venda{
    private:
        int codigo;
        Cliente cliente;
        vector<Produto> produtos;
    public:
        Venda(int codigo, Cliente cliente, vector<Produto> produtos);
        void setCodigo (int codigo);
        int getCodigo ();
        void setCliente (Cliente cliente);
        Cliente getCliente ();
        void setProdutos (vector<Produto> produtos);
        vector<Produto> getProdutos ();
};