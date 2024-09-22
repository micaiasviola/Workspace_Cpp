#include <iostream> // Biblioteca padrão de entrada e saída em C++
#include <clocale>  // Para setlocale
#include <limits>   // Para numeric_limits
#include <cstdlib> // Para exit()

void limparTela() {
    // Limpa a tela dependendo do sistema operacional
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int obterOpcao() {
    int numero = 0;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Cadastrar usuario\n";
        std::cout << "2. Autenticar usuario\n";
        std::cout << "3. Limpar Menu\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha uma opcao: ";

        if (std::cin >> numero) {
            if (numero >= 1 && numero <= 4) {
                return numero; // Retorna a opção válida
            } else {
                std::cout << "Opção inválida. Tente novamente." << std::endl;
            }
        } else {
            std::cout << "Entrada inválida. Tente novamente." << std::endl;
            std::cin.clear(); // Limpa o estado de erro de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.get(); // Espera o usuário pressionar Enter
        limparTela(); // Limpa a tela após uma entrada inválida
    }
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao;

    do {
        opcao = obterOpcao(); // Chama a função para obter a opção

        switch (opcao) {
            case 1:
                std::cout << "Cadastrar um usuário." << std::endl;
                std::cin.get();
                break;
            case 2:
                std::cout << "Autenticar Usuário." << std::endl;
                std::cin.get();
                break;
            case 3:
                std::cout << "Limpar menu." << std::endl;
                std::cin.get();
                break;
            case 4:
                std::cout << "Saindo..." << std::endl;
                exit(0);
            default:
                break; // Essa linha nunca deve ser atingida
        }

        std::cout << "Pressione Enter para continuar...";
        std::cin.get(); // Espera o usuário pressionar Enter antes de limpar a tela
        limparTela(); // Limpa a tela após executar a opção
    } while (opcao != 4); // Loop até que a opção 4 (sair) seja escolhida

    return 0; // Finaliza o programa
}
