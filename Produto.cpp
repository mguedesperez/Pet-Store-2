#include "Produto.h"
using namespace std;

Produto::Produto (int codigo, string descricao, float valor){
    setCodigo(codigo);
    setDescricao(descricao);
    setValor(valor);
}
Produto::Produto (int codigo, string descricao, float valor, int quantidade){
    setCodigo(codigo);
    setDescricao(descricao);
    setValor(valor);
    setQuantidade(quantidade);
}
void Produto::setCodigo (int cod){
    codigo = cod;
}
int Produto::getCodigo (){
    return codigo;
}
void Produto::setDescricao (string desc){
    descricao = desc;
}
string Produto::getDescricao (){
    return descricao;
}
void Produto::setValor (float val){
    valor = val;
}
float Produto::getValor (){
    return valor;
}
void Produto::setQuantidade (int quant){
    quantidade = quant;
}
int Produto::getQuantidade (){
    return quantidade;
}