#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Produto.cpp"
#include "Cliente.cpp"
#include "Venda.cpp"

using namespace std;

//Carrega a lista de produtos do arquivo estoque.txt
void carregar(vector<Produto> & lista) {

    int codigo;
    string descricao;
    float valor;
    int quantidade;

	ifstream estoque;

	estoque.open("estoque.txt");
	
	if ( ! estoque.is_open() ) {
		cerr << "Erro ao abrir arquivo de entrada!" << endl;
		exit(-1);
	}
	
	estoque >> codigo;
	estoque >> descricao;
	estoque >> valor;
	estoque >> quantidade;	 

	while (estoque.good()) {
			
		Produto p(codigo,descricao,valor,quantidade);
		lista.push_back(p);
		
		estoque >> codigo;
		estoque >> descricao;
		estoque >> valor;
		estoque >> quantidade;	 
	
	}
	estoque.close();

}

//Imprime na tela a lista de produtos
void mostrar(vector<Produto> lista) {
	for(int i = 0; i < lista.size(); i++) {
		cout << lista[i].getCodigo() << " - " << lista[i].getDescricao() << " - " << lista[i].getValor() << endl;
	}
}


//Core do sistema. Vendas dos produtos em estoque.
void venda(vector<Produto> & estoque, vector<Produto> & carrinho) {
    int codigo;
    int quantidade;

    while (true) {
        
        cout << "\n#########" << endl;
        cout << "Pet Store" << endl;
        cout << "#########\n" << endl;

        while (true){
            cout << "Produtos disponiveis:" << endl;
            mostrar(estoque);
            cout << "Digite o codigo do produto para adicionar ao carrinho: (0 - Finalizar)" << endl;
            cin >> codigo;

            if (codigo == 0) {
                break;
            }
            else{
                bool encontrou = false;
                for(int i = 0; i < estoque.size(); i++) {
                    if (estoque[i].getCodigo() == codigo){
                        encontrou = true;
                        if(estoque[i].getQuantidade() > 0){
                            cout << "Digite a quantidade" << endl;
                            cin >> quantidade;
                            if(quantidade <= estoque[i].getQuantidade()){
                                Produto novo (estoque[i].getCodigo(), estoque[i].getDescricao(), estoque[i].getValor(), quantidade); 
                                carrinho.push_back(novo);
                                estoque[i].setQuantidade(estoque[i].getQuantidade()-quantidade);

                                cout << "\n**" << endl;
                                cout << "Voce adicionou "<< quantidade << " unidades de " << estoque[i].getDescricao()  << endl;
                                cout << "**\n" << endl;
                            }
                            else{
                                cout << "\n*Quantidade indisponivel*\n"  << endl;
                                break;
                            }
                        }
                        else{
                            cout << "\n*Produto indisponivel*\n"  << endl;
                            break;
                        }
                        break;
                    }
                }
                if (!encontrou){
                    cout << "\n*Produto inexistente*\n" << endl;
                }
            }
        }
        break;

    }
    cout << "\nCompra finalizada. Verifique o relatorio com os dados.\n" << endl;
    cout << "\nObrigado. Volte sempre!\n" << endl;

}

//Imprime o relatório de vendas e os recibos dos clientes
void relatorio(vector<Produto> estoque, vector<Venda> vendas){
    ofstream relatorio;
    cout << "Gravando relatorio de vendas..." << endl;

    relatorio.open("relatorio.txt");

    //Imprime o estoque atual, com as quantidades atualizadas 
    relatorio << "Estoque atual" << endl;
    for(int i = 0; i < estoque.size(); i++) {
        relatorio << estoque[i].getCodigo() << " - " << estoque[i].getDescricao() << " - " << estoque[i].getValor() << " - " << estoque[i].getQuantidade() << endl;
    }

    //Imprime o relatório de todas as vendas efetuadas
    relatorio << "\nVocê realizou "<< vendas.size() << " vendas." << endl;
    float geral = 0;
    for(int i = 0; i < vendas.size(); i++) {
        relatorio << "\nVenda "<< i+1 << endl;
        float total = 0;
        for(int j = 0; j < vendas[i].getProdutos().size(); j++) {
            relatorio << vendas[i].getProdutos()[j].getCodigo() << " - " << vendas[i].getProdutos()[j].getDescricao() << " - " << "Parcial = " << vendas[i].getProdutos()[j].getValor() * vendas[i].getProdutos()[j].getQuantidade() << endl;
            total = total + (vendas[i].getProdutos()[j].getValor() * vendas[i].getProdutos()[j].getQuantidade());
        }
        geral = geral + total;
        relatorio << "Total = "<< total << endl;
    }
    relatorio << "\nTOTAL GERAL = "<< geral << endl;

    relatorio.close();

    //Imprime os recibos de todas as vendas
    cout << "Gravando recibos de venda..." << endl;
    for(int i = 0; i < vendas.size(); i++) {
        Cliente cli = vendas[i].getCliente();
        vector<Produto> carrinho = vendas[i].getProdutos();
        ofstream recibo;

        //Gera o arquivo de recibo com o cpf do cliente
        recibo.open("recibo_"+cli.getCpf()+".txt");

        recibo << "\nRecibo " << cli.getNome() << " - " << cli.getCpf() << endl;
        float total = 0;
        for(int j = 0; j < carrinho.size(); j++) {
            recibo << carrinho[j].getCodigo() << " - " << carrinho[j].getDescricao() << " - " << carrinho[j].getValor() << " Parcial = " << carrinho[j].getValor() * carrinho[j].getQuantidade() << endl;
            total = total + (carrinho[j].getValor() * carrinho[j].getQuantidade());
        }
        recibo << "Total = "<< total << endl;

        recibo.close();
    }

}


int main(){
    vector<Produto> estoque;
    vector<Venda> vendas;

	carregar(estoque);

    while (true){
        vector<Produto> carrinho;
        
        int opcao;
        cout << "\n Ola, deseja comprar? (1 - Sim, 0 - Nao)" << endl;
        cin >> opcao;
        if(opcao == 0){
            break;
        }
        string nome, cpf, dataNascimento;
        cout << "Digite seu nome" << endl;
        cin >> nome;
        cin.sync();
        cout << "Digite seu cpf" << endl;
        cin >> cpf;
        cout << "Digite sua data de nascimento" << endl;
        cin >> dataNascimento;
        Cliente cliente(nome, cpf, dataNascimento);
        venda(estoque, carrinho);
        Venda v(vendas.size()+1,cliente,carrinho);
        vendas.push_back(v);
    }

    relatorio(estoque, vendas);
    return 0;
}