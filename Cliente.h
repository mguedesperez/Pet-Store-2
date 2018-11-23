using namespace std;

class Cliente{
    private:
        string nome;
        string cpf;
        string dataNascimento;
    public:
        Cliente();
        Cliente (string nome, string cpf, string dataNascimento);
        void setNome (string nome);
        string getNome ();
        void setCpf(string cpf);
        string getCpf ();
        void setDataNascimento (string dataNascimento);
        string getDataNascimento ();
};