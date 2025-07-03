#include<iostream>
#include<string>

void menu(){
    std::cout << "\n------ \033[33mBanco\033[0m ------";
    std::cout << "\n[1] Depositar.\n[2] Sacar.\n[3] Consultar Saldo.\n[4] Informações Gerais.\n[5] Sair.\n";
}

void alerro(){
        std::cout << "\n\033[30;43m[ALERT!]\033[0m \033[31mValor Inválido.\033[0m\n";
    }

class ContaBancaria{
    private:
    std::string Titular;
    double saldo;

    public:
    ContaBancaria(double s, std::string T){
        saldo = s;
        Titular = T;
    }
    void depositar(double valor){
        saldo += valor;
        std::cout << "\nR$\033[32m" << valor << "\033[0m Depositados.\n";
    }

    void sacar(double valor){
        saldo -= valor;
        std::cout << "\nR$\033[32m" << valor << "\033[0m Sacados.\n";
    }
    void ver_saldo(){
        std::cout << "Saldo atual: \033[32m" << saldo << "\033[0m\n";
    }

    double getsaldo(){
        return saldo;
    }

    std::string getnome(){
        return Titular;
    }
};

int main(){
    int opcao = 0;
    double v = 0;
    ContaBancaria conta(500.75, "Kauann Senna");

    while (opcao != 5){
        menu();
        std::cout << "\nEscolha: ";
        std::cin >> opcao;
        switch (opcao){
            case 1:
                std::cout << "\nValor: ";
                std::cin >> v;

                if (v <= 0){
                    alerro();
                }else{
                    conta.depositar(v);
                }
                break;
            case 2:
                std::cout << "\nValor: ";
                std::cin >> v;

                if (v > conta.getsaldo() or v <= 0){
                    alerro();
                }else{
                    conta.sacar(v);
                }
                break;
            case 3:
                conta.ver_saldo();
                break;
            case 4:
                std::cout << "\nNome do Titular: \033[1m" << conta.getnome() << "\033[0m\nSaldo: \033[32m" << conta.getsaldo() << "\033[0m\n";
                break;
            case 5:
                std::cout << "\n\033[1mSaindo...\033[0m\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    }
    return 0;
}