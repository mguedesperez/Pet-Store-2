#include <iostream>

using namespace std;

class Venda{
    private:
        int codigo;
        Cliente cliente;
        vector<Produto> produtos;

    public:
        Venda(int codigo, Cliente cliente, vector<Produto> produtos){
            this->codigo = codigo;
            this->cliente = cliente;
            this->produtos = produtos;
        }

        void setCodigo (int codigo){
            this->codigo = codigo;
        }
        int getCodigo (){
            return codigo;
        }
        void setCliente (Cliente cliente){
            this->cliente = cliente;
        }
        Cliente getCliente (){
            return cliente;
        }
        void setProdutos (vector<Produto> produtos){
            this->produtos = produtos;
        }
        vector<Produto> getProdutos (){
            return produtos;
        }

};