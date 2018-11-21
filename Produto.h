#include <iostream>

using namespace std;

class Produto{
    private:
        int codigo;
        string descricao;
        float valor;
        int quantidade;

    public:
        Produto (int codigo, string descricao, float valor){
            this->codigo = codigo;
            this->descricao = descricao;
            this->valor = valor;
        }
        Produto (int codigo, string descricao, float valor, int quantidade){
            this->codigo = codigo;
            this->descricao = descricao;
            this->valor = valor;
            this->quantidade = quantidade;
        }

        void setCodigo (int codigo){
            this->codigo = codigo;
        }
        int getCodigo (){
            return codigo;
        }
        void setDescricao (string descricao){
            this->descricao = descricao;
        }
        string getDescricao (){
            return descricao;
        }
        void setValor (float valor){
            this->valor = valor;
        }
        float getValor (){
            return valor;
        }
        void setQuantidade (int quantidade){
            this->quantidade = quantidade;
        }
        int getQuantidade (){
            return quantidade;
        }
};