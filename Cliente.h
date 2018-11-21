#include <iostream>

using namespace std;

class Cliente{

    public:
        string nome;
        string cpf;
        string dataNascimento;

        Cliente(){
        
        }
        Cliente (string nome, string cpf, string dataNascimento){
            this->nome = nome;
            this->cpf = cpf;
            this->dataNascimento = dataNascimento;
        }

        void setNome (string nome){
            this->nome = nome;
        }
        string getNome (){
            return nome;
        }
        void setCpf (string cpf){
            this->cpf = cpf;
        }
        string getCpf (){
            return cpf;
        }
        void setDataNascimento (string dataNascimento){
            this->dataNascimento = dataNascimento;
        }
        string getDataNascimento (){
            return dataNascimento;
        }
};