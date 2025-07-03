#include<iostream>
#include<string>
#include<limits>

void menu(){
    std::cout << "\n------ \033[33mBanco\033[0m ------";
    std::cout << "\n[1] Depositar.\n[2] Sacar.\n[3] Consultar Saldo.\n[4] Informações Gerais.\n[5] Sair.\n";
}

void alert_erro(std::string mensage){
    std::cout << "\n\033[30;43m[ALERT!]\033[0m" << "\033[31m " << mensage <<"\033[0m\n";
}

class ContaBancaria{//Classes devem ter nomes em Maiúsculo//
    private:
    std::string titular; //Atributos devem ter nomes em minúsculo//
    double saldo;

    public:
    ContaBancaria(double s, std::string T){
        saldo = s;
        titular = T;
    }
    void depositar(double valor){
        if (valor <= 0){
                    alert_erro("Não é possível depositar um valor nulo/negativo.");
                }else{
                    saldo += valor;
                    std::cout << "\nR$\033[32m" << valor << "\033[0m Depositados.\n";
                }
    }

    void sacar(double valor){
        if (valor > saldo or valor <= 0){
            alert_erro("Não é possível sacar um valor maior que o saldo ou negativo.");
            }else{
                saldo -= valor;
                std::cout << "\nR$\033[32m" << valor << "\033[0m Sacados.\n";
                }
    }
    void consultarsaldo(){
        std::cout << "\nSaldo atual: \033[32m" << saldo << "\033[0m\n";
    }

    double getSaldo() const{
        return saldo;
    }

    std::string getNome() const{
        return titular;
    }
};

int main(){
    int opcao = 0;
    double v = 0;
    ContaBancaria conta(500.75, "Kauann Senna");

    while (opcao != 5){
        menu();
        std::cout << "\nEscolha: ";
        if(std::cin >> opcao){
            switch (opcao){
                case 1:
                    std::cout << "\nValor: ";
                    if(std::cin >> v){
                        conta.depositar(v);
                    }else{
                        alert_erro("A entrada deve ser um número.");
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
    
                    break;
                case 2:
                    std::cout << "\nValor: ";
                    if(std::cin >> v){
                        conta.sacar(v);
                    }else{
                        alert_erro("A entrada deve ser um número.");
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

                    break;
                case 3:
                    conta.consultarsaldo();
                    break;
                case 4:
                    std::cout << "\nNome do Titular: \033[1m" << conta.getNome() << "\033[0m\nSaldo: \033[32m" << conta.getSaldo() << "\033[0m\n";
                    break;
                case 5:
                    std::cout << "\n\033[1mSaindo...\033[0m\n";
                    break;
                default:
                    std::cout << "\nOpção inválida.\n";
            }
        }else{
            alert_erro("A entrada deve ser um inteiro (1-5). ");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}