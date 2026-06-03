#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Integrantes: Anderson, Inacio, Igor e Gabriel Marques
//Nome do projeto: PetShop

struct Pet {
    char especie[10];
    char raca[10];
    char nomePet[20];
    char dono[20];
    char porte[10];
    float preco;
};

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int opcao;

    do {
        printf("\n=========================================\n");
        printf("             Menu do Petshop             \n");
        printf("=========================================\n");
        printf("1. Serviço de tosa para cachorro\n");
        printf("2. Serviço de tosa para gato\n");
        printf("3. Serviço de banho para cachorro\n");
        printf("4. Serviço de banho para gato\n");
        printf("5. Serviço de banho e tosa para cachorro\n");
        printf("6. Serviço de banho e tosa para gato\n");
        printf("0. Sair do programa\n");
        printf("=========================================\n");
        printf("Insira uma das opções acima: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n[Opção 1] Você escolheu: Serviço de tosa para cachorro.\n");
                // Insira a lógica ou chamada de função para a opção 1 aqui
                break;
                
            case 2:
                printf("\n[Opção 2] Você escolheu: Serviço de tosa para gato.\n");
                // Insira a lógica ou chamada de função para a opção 2 aqui
                break;
                
            case 3:
                printf("\n[Opção 3] Você escolheu: Serviço de banho para cachorro.\n");
                // Insira a lógica ou chamada de função para a opção 3 aqui
                break;
                
            case 4:
                printf("\n[Opção 4] Você escolheu: Serviço de banho para gato.\n");
                // Insira a lógica ou chamada de função para a opção 4 aqui
                break;
                
            case 5:
                printf("\n[Opção 5] Você escolheu: Serviço de banho e tosa para cachorro.\n");
                // Insira a lógica ou chamada de função para a opção 5 aqui
                break;
                
            case 6:
                printf("\n[Opção 6] Você escolheu: Serviço de banho e tosa para gato.\n");
                // Insira a lógica ou chamada de função para a opção 6 aqui
                break;
                
            case 0:
                printf("\nSaindo do sistema... Obrigado!\n");
                break;
                
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 0); // O loop continua rodando enquanto a opção não for 0

    return 0;
}
