#include "Cliente.h"
using namespace std;

Cliente::Cliente() {}
Cliente::Cliente (string nome, string cpf, string dataNascimento){
    setNome(nome);
    setCpf(cpf);
    setDataNascimento(dataNascimento);
}

void Cliente::setNome (string n ){
    nome = n ;
}
string Cliente::getNome (){
    return nome;
}
void Cliente::setCpf (string c ){
    cpf = c;
}
string Cliente::getCpf (){
    return cpf;
}
void Cliente::setDataNascimento (string dtNascimento){
    dataNascimento = dtNascimento;
}
string Cliente::getDataNascimento (){
    return dataNascimento;
}