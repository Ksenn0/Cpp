#include<iostream>
#include<string>

int main(){
    std::string nome;
    int idade;

    std::cout << "Digite seu nome completo: ";
    std::getline(std::cin, nome);
    std::cout << "Digite sua idade: ";
    std::cin >> idade;
    
    std::cout << "Contando até " << idade << ":\n";
    for(int i = 1; i <= idade; i++){
        std::cout << i << " ";
    }

    std::cout << "\nSeu nome é: " << nome;
    std::cout << "\nSua idade é: " << idade << " anos\n";
    std::cout << "você é considerado: ";

    if(idade < 0 || idade > 120){
        std::cout << "Idade inválida!\n";
    }else if(idade < 14){
        std::cout << "Criança\n";
    }else if(idade > 14 && idade < 18){
        std::cout << "Adolecente\n";
    }else if(idade >= 18 && idade < 60){
        std::cout << "Adulto\n";
    }else if(idade >= 60){
        std::cout << "Idoso\n";
    }

    return 0;
}