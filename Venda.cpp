#include "Venda.h"

using namespace std;

Venda::Venda(int codigo, Cliente cliente, vector<Produto> produtos){
    setCodigo(codigo);
    setCliente(cliente);
    setProdutos(produtos);
}

void Venda::setCodigo (int cod){
    codigo = cod;
}
int Venda::getCodigo (){
    return codigo; 
 }
void Venda::setCliente (Cliente cli){
    cliente = cli;
        }
Cliente Venda::getCliente (){
    return cliente;
        }
void Venda::setProdutos (vector<Produto> prods){
    produtos = prods;
        }
vector<Produto> Venda::getProdutos (){
    return produtos;
}